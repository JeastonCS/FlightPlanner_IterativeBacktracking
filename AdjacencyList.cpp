//
// Created by Jack Easton on 3/28/2020.
//

#include "AdjacencyList.h"
#include "LinkList.h"
#include "LinkListIterator.h"
#include "OriginCity.h"
#include <fstream>
#include <iostream>
using namespace std;

AdjacencyList::AdjacencyList(char *fileName) {
    originCities = * new LinkList<OriginCity>;
    iter = * new LinkListIterator<OriginCity>;

    initializeWithFile(fileName);
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
        DSString destinationCity = * new DSString(destination);

        DSString costString = * new DSString(costChar);
        DSString timeString = * new DSString(timeChar);
        int cost = costString.toInt();
        int time = timeString.toInt();

        addOriginDestinationPair(originCity, destinationCity, cost, time);
    }

    //set the iterators in each OriginCity to their their begin() values
    for (iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        originCities.at(iter).setIterators();
    }

    flightData.close();
}

void AdjacencyList::addOriginDestinationPair(const DSString &originCity, const DSString &destinationCity, int cost, int time) {
    if (originCities.isEmpty()) {
        OriginCity origin1 = * new OriginCity(originCity, destinationCity, cost, time);
        originCities.push_back(origin1);
        OriginCity origin2 = * new OriginCity(destinationCity, originCity, cost, time);
        originCities.push_back(origin2);
    }
    else {
        //check if origin is on list
        findOriginCity(originCity);
        if (iter.getCurrIndex() == -1) { //if not, add origin and destination
            OriginCity origin = * new OriginCity(originCity, destinationCity, cost, time);
            originCities.push_back(origin);
        }
        else { //if it is, add destination to the origin city
            originCities.at(iter).addDestination(destinationCity, cost, time);
        }

        //check if destination is on list
        findOriginCity(destinationCity);
        if (iter.getCurrIndex() == -1) { //if not, add destination as an origin city and its destination (aka originCity)
            OriginCity origin = * new OriginCity(destinationCity, originCity, cost, time);
            originCities.push_back(origin);
        }
        else { //if it is, add originCity as a destination of destinationCity
            originCities.at(iter).addDestination(originCity, cost, time);
        }
    }
}

AdjacencyList & AdjacencyList::operator=(const AdjacencyList &rhs) {
    this->originCities = rhs.originCities;
    iter = * new LinkListIterator<OriginCity>;

    return *this;
}

void AdjacencyList::findOriginCity (const DSString &originCity) {
    for (iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        if (originCities.at(iter).getOriginName() == originCity) {
            return;
        }
    }
    iter = * new LinkListIterator<OriginCity>;
}

OriginCity * AdjacencyList::originCityAt(const DSString &originCity) {
    bool found = false;
    for (iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        if (originCities.at(iter).getOriginName() == originCity) {
            return &originCities.at(iter);
        }
    }
    return nullptr;
}

void AdjacencyList::print() {
    for (auto iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        OriginCity currCity = originCities.at(iter);
        currCity.print();
    }
}
