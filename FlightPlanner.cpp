//
// Created by Jack Easton on 4/5/2020.
//

#include "FlightPlanner.h"

FlightPlanner::FlightPlanner(const AdjacencyList &adjList, char *requests, char *outputName) {
    list = adjList;
    flights = * new DSVector<Flight>;

    initializeFlights(requests);
    planFlights();
    outputToFile(outputName);
}

void FlightPlanner::initializeFlights(char *requests) {
    ifstream requestedFlights(requests);
    if (!requestedFlights) {
        cout << "could not open requested flights" << endl;
        exit(1);
    }

    int numFlights;
    requestedFlights >> numFlights;
    requestedFlights.ignore();

    for (int i = 0; i < numFlights; i++) {
        char origin[20];
        char destination[20];
        char sortingChar[2];
        requestedFlights.getline(origin, 20, '|');
        requestedFlights.getline(destination, 20, '|');
        requestedFlights.getline(sortingChar, 2);

        DSString originCity = * new DSString(origin);
        DSString destinationCity = * new DSString(destination);
        DSString sortingCharacteristic = * new DSString(sortingChar);

        Flight flight = * new Flight(originCity, destinationCity, sortingCharacteristic);
        flights.push_back(flight);
    }

    requestedFlights.close();
}

void FlightPlanner::planFlights() {
    for (int i = 0; i < flights.size(); i++) {
        flights.at(i).initializePossiblePaths(list);
        flights.at(i).narrowToTopThree();
    }
}

void FlightPlanner::outputToFile(char *outputName) {
    ofstream outFile(outputName);
    for (int i = 0; i < flights.size(); i++) {
        flights.at(i).printToFile(outFile);
    }

    outFile.close();
}
