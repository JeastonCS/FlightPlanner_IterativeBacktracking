//
// Created by Jack Easton on 3/28/2020.
//

#include "Flight.h"
#include "Stack.h"

Flight::Flight(const DSString &origin, const DSString &dest, const DSString &sortingChar) {
    originCity = origin;
    destinationCity = dest;
    sortingCharacteristic = sortingChar;
}

void Flight::initializePossiblePaths(const AdjacencyList &adjList) {
    Stack<DSString> stack;

}

void Flight::getTopThreePaths() {

}
