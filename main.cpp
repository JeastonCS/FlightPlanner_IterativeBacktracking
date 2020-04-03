//#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"

#include "DSString.h"
#include "DSVector.h"
#include "LinkList.h"
#include "AdjacencyList.h"
#include "Flight.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

//    if (argc == 1) {
//        Catch::Session().run();
//    }


    //create adjacency list from file
    AdjacencyList list(argv[1]);
//    list.print();

    //create vector of flights from file
    ifstream requestedFlights(argv[2]);
    if (!requestedFlights) {
        cout << "could not open requested flights" << endl;
        exit(1);
    }

    DSVector<Flight> flights;

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

    //loop through vector of flights and call initializePossiblePaths(w/ ^list) AND getTopThreePaths() on each Flight in vector
    for (int i = 0; i < flights.size(); i++) {
//        Flight flight();
        flights.at(i).initializePossiblePaths(list);
        flights.at(i).getTopThreePaths();
    }

    //loop through flights and output top three flights to file
    ofstream outFile("OutFile.txt");
    for (int i = 0; i < flights.size(); i++) {
        flights.at(i).printToFile(outFile);
    }

    outFile.close();

    return 0;
}
