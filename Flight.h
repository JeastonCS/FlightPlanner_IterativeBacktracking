//
// Created by Jack Easton on 3/28/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_FLIGHT_H
#define S20_PA04_FLIGHTPLANNER_FLIGHT_H

#include "DSString.h"
#include "DSVector.h"
#include "Path.h"
#include "AdjacencyList.h"

class Flight {
private:
    DSString originCity;
    DSString destinationCity;
    DSString sortingCharacteristic;

    DSVector<Path> possiblePaths;
public:
    Flight(const DSString &, const DSString &, const DSString &);

    void initializePossiblePaths(const AdjacencyList &adjList);
    void getTopThreePaths();

    DSString & getOriginCity() { return originCity; }
    DSString & getDestinationCity() { return destinationCity; }
};


#endif //S20_PA04_FLIGHTPLANNER_FLIGHT_H
