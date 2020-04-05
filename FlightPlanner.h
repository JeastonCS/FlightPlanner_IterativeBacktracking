//
// Created by Jack Easton on 4/5/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_FLIGHTPLANNER_H
#define S20_PA04_FLIGHTPLANNER_FLIGHTPLANNER_H

#include <fstream>
#include "DSVector.h"
#include "Flight.h"
#include "AdjacencyList.h"

class FlightPlanner {
private:
    DSVector<Flight> flights;
    AdjacencyList list;
public:
    FlightPlanner(const AdjacencyList &, char *, char *);
private:
    void initializeFlights(char *);
    void planFlights();
    void outputToFile(char *);
};


#endif //S20_PA04_FLIGHTPLANNER_FLIGHTPLANNER_H
