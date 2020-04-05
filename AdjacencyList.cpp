//
// Created by Jack Easton on 3/28/2020.
//

#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    originCities = * new LinkList<OriginCity>;
}

AdjacencyList::AdjacencyList(char *fileName) {
    originCities = * new LinkList<OriginCity>;
    initializeWithFile(fileName);
}

AdjacencyList & AdjacencyList::operator=(const AdjacencyList &rhs) {
    this->originCities = rhs.originCities;
    return *this;
}

void AdjacencyList::initializeWithFile(char *fileName) {
    ifstream flightData(fileName);
    if (!flightData) {
        cout << "could not open flight data file" << endl;
        exit(1);
    }

    int numFlights;
    flightData >> numFlights;
    flightData.ignore();

    //get each origin/destination pair from file and add to Adjacency List
    for (int i = 0; i < numFlights; i++) {
        char origin[20];
        char destination[20];
        char costChar[10];
        char timeChar[10];
        flightData.getline(origin, 20, '|');
        flightData.getline(destination, 20, '|');
        flightData.getline(costChar, 10, '|');
        flightData.getline(timeChar, 10);

        DSString originCity = * new DSString(origin);
        DSString destinationName = * new DSString(destination);
        DSString cost = * new DSString(costChar);
        DSString time = * new DSString(timeChar);

        addOriginDestinationPair(originCity, destinationName, cost.toInt(), time.toInt());
    }

    //set the iterators in each OriginCity to their their begin() values
    for (auto iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        originCities.at(iter).setIterators();
    }

    flightData.close();
}

void AdjacencyList::addOriginDestinationPair(const DSString &originName, const DSString &destinationName, int cost, int time) {
    DestinationCity destinationCity = * new DestinationCity(destinationName, cost, time);
    DestinationCity originAsDestination = * new DestinationCity(originName, cost, time);

    if (originCities.isEmpty()) {
        OriginCity origin1 = * new OriginCity(originName, destinationCity);
        originCities.push_back(origin1);

        OriginCity origin2 = * new OriginCity(destinationName, originAsDestination);
        originCities.push_back(origin2);
    }
    else {
        //check if origin is on list
        auto iter = findOriginCity(originName);
        if (iter.getCurrIndex() == -1) { //if not, add origin and destination
            OriginCity origin = * new OriginCity(originName, destinationCity);
            originCities.push_back(origin);
        }
        else { //if it is, add destination to the origin city
            originCities.at(iter).addDestination(destinationCity);
        }

        //check if destination is on list
        iter = findOriginCity(destinationName);
        if (iter.getCurrIndex() == -1) { //if not, add destination as an origin city and its destination (aka originCity)
            OriginCity origin = * new OriginCity(destinationName, originAsDestination);
            originCities.push_back(origin);
        }
        else { //if it is, add originCity as a destination of destinationCity
            originCities.at(iter).addDestination(originAsDestination);
        }
    }
}

LinkListIterator<OriginCity> AdjacencyList::findOriginCity (const DSString &originCity) {
    for (auto iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        if (originCities.at(iter).getOriginName() == originCity) {
            return iter;
        }
    }
    return nullptr;
}

OriginCity * AdjacencyList::originCityAt(const DSString &originCity) {
    bool found = false;
    for (auto iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        if (originCities.at(iter).getOriginName() == originCity) {
            return &originCities.at(iter);
        }
    }
    return nullptr;
}

void AdjacencyList::print() {
    for (auto iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        originCities.at(iter).print();
        cout << endl;
    }
}
