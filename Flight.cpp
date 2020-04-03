//
// Created by Jack Easton on 3/28/2020.
//

#include "Flight.h"
#include "Stack.h"
#include "Path.h"

Flight::Flight() {
    originCity = "";
    destinationCity = "";
    sortingCharacteristic = "";

    possiblePaths = * new DSVector<Path>;
}

Flight::Flight(const Flight &toCopy) {
    originCity = toCopy.originCity;
    destinationCity = toCopy.destinationCity;
    sortingCharacteristic = toCopy.sortingCharacteristic;

    possiblePaths = toCopy.possiblePaths;
}

Flight::Flight(const DSString &origin, const DSString &dest, const DSString &sortingChar) {
    originCity = origin;
    destinationCity = dest;
    sortingCharacteristic = sortingChar;

    possiblePaths = * new DSVector<Path>;
}

Flight &Flight::operator=(const Flight &rhs) {
    originCity = rhs.originCity;
    destinationCity = rhs.destinationCity;
    sortingCharacteristic = rhs.sortingCharacteristic;
    possiblePaths = rhs.possiblePaths;

    return *this;
}

void Flight::initializePossiblePaths(AdjacencyList &adjList) {

    Stack<OriginCity> stack;

    stack.push_back(*adjList.originCityAt(originCity));

    int cost = 0;
    int time = 0;
    while (!stack.isEmpty()) {
        if (stack.getBack().getOriginName() == destinationCity) {
            Path path = * new Path(stack.getList(), calculateCost(stack.getList()), calculateTime(stack.getList()));
            possiblePaths.push_back(path);
            stack.pop_back();
        }
        else {
            //
            bool pushed = false;
            while (stack.getBack().getDestinationsIter().hasNext()) {
                OriginCity *destinationCity = adjList.originCityAt(stack.getBack().getDestinationsIter().getCurrPosition()->getData());

                stack.getBack().moveToNextDestination();
                if (!stack.contains(*destinationCity)) {
                    stack.push_back(*destinationCity);
                    pushed = true;
                    break;
                }
            }
            if (!pushed) { //never pushed back another OriginCity - ran through backCity's destinations
                stack.getBack().getDestinationsIter() = stack.getBack().getDestinationsBegin();

                stack.pop_back();
            }
        }
    }
}

int Flight::calculateCost(LinkList<OriginCity> &list) {
    int cost = 0;
    for (auto iter = list.begin(); iter <= list.end(); iter.operator++()) {
        for (auto costIter = list.at(iter).getCostIteratorBegin(); costIter <= list.at(iter).getCostListEnd(); costIter.operator++())
            cost += costIter.getCurrPosition()->getData();
    }

    return cost;
}

int Flight::calculateTime(LinkList<OriginCity> &list) {
    int time = 0;
    for (auto iter = list.begin(); iter <= list.end(); iter.operator++()) {
        for (auto timeIter = list.at(iter).getTimeIteratorBegin(); timeIter <= list.at(iter).getTimeListEnd(); timeIter.operator++())
            time += timeIter.getCurrPosition()->getData();
    }

    return time;
}

void Flight::getTopThreePaths() {
        DSVector<Path> topThreePaths = * new DSVector<Path>;

        int size;
        if (possiblePaths.size() > 3)
            size = 3;
        else
            size = possiblePaths.size();

        if (sortingCharacteristic == "T") {
            for (int i = 0; i < size; i++) {
                int min = 999999999;
                int minIndex = -1;
                for (int j = 0; j < possiblePaths.size(); j++) {
                    if (possiblePaths.at(j).getTime() < min) {
                        minIndex = j;
                        min = possiblePaths.at(j).getTime();
                    }
                }

                topThreePaths.push_back(possiblePaths.at(minIndex));
                possiblePaths.removeAt(minIndex);
            }
        }
        else {
            for (int i = 0; i < size; i++) {
                int min = 999999999;
                int minIndex = -1;
                for (int j = 0; j < possiblePaths.size(); j++) {
                    if (possiblePaths.at(j).getCost() < min) {
                        minIndex = j;
                        min = possiblePaths.at(j).getCost();
                    }
                }
                if (minIndex >= 0)
                    topThreePaths.push_back(possiblePaths.at(minIndex));
            }
        }

        possiblePaths = topThreePaths;
}

void Flight::printToFile(ofstream &outFile) {
    //print requested flight
    outFile << "Flight: " << originCity << ", " << destinationCity;
    if (sortingCharacteristic == "T") {
        outFile << " (Time)" << endl;
    }
    else {
        outFile << " (Cost)" << endl;
    }

    //print top 3 paths
    for (int i = 0; i < possiblePaths.size(); i++){
        outFile << "\tPath " << i+1 << ": ";

        //print linklist attribute of path
        int size = possiblePaths.at(i).getPath().getSize();
        auto iter = possiblePaths.at(i).getPath().begin();
        for(int j = 0; j < size - 1; j++) {
            outFile << iter.next() << " -> ";
        }
        outFile << iter.next() << ". ";

        //print time and cost for this path
        outFile << "Time: " << possiblePaths.at(i).getTime() << " minutes / ";
        outFile << "Cost: $" << possiblePaths.at(i).getCost() << ".00";
        outFile << endl;
    }
    outFile << endl;

}
