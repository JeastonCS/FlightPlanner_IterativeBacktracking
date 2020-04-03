//
// Created by Jack Easton on 3/28/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_FLIGHT_H
#define S20_PA04_FLIGHTPLANNER_FLIGHT_H

#include "DSString.h"
#include "DSVector.h"
#include "Path.h"
#include "AdjacencyList.h"

#include <fstream>

class Flight {
private:
    DSString originCity;
    DSString destinationCity;
    DSString sortingCharacteristic;

    DSVector<Path> possiblePaths;
public:
    Flight();
    Flight(const Flight &);
    Flight(const DSString &, const DSString &, const DSString &);

    Flight & operator= (const Flight &);

    void initializePossiblePaths(AdjacencyList &adjList);
    void getTopThreePaths();
    int calculateCost(LinkList<OriginCity> &);
    int calculateTime(LinkList<OriginCity> &);
    void printToFile(ofstream &);

    DSString & getOriginCity() { return originCity; }
    DSString & getDestinationCity() { return destinationCity; }
};


#endif //S20_PA04_FLIGHTPLANNER_FLIGHT_H
