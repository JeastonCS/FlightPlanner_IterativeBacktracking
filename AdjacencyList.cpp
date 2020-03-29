//
// Created by Jack Easton on 3/28/2020.
//

#include "AdjacencyList.h"
#include "LinkList.h"
#include "LinkListIterator.h"
#include "OriginCity.h"

AdjacencyList::AdjacencyList() {
    originCities = * new LinkList<OriginCity>;
    iter = * new LinkListIterator<OriginCity>;
}

void AdjacencyList::addOriginDestinationPair(DSString &originCity, DSString &destinationCity) {
    //check if origin is on list
    findOriginCity(originCity);
    if (iter.getCurrIndex() == -1) { //if not, add origin and destination
        OriginCity origin(originCity, destinationCity);
        originCities.push_back(origin);
    }
    else { //if it is, add destination to the origin city
        originCities.at(iter).addDestination(destinationCity);
    }

    //check if destination is on list
    findOriginCity(destinationCity);
    if (iter.getCurrIndex() == -1) { //if not, add destination as an origin city and its destination (aka originCity)
        OriginCity origin(destinationCity, originCity);
        originCities.push_back(origin);
    }
    else { //if it is, add originCity as a destination of destinationCity
        originCities.at(iter).addDestination(originCity);
    }
}

AdjacencyList & AdjacencyList::operator=(const AdjacencyList &rhs) {
    this->originCities = rhs.originCities;
    iter = nullptr;

    return *this;
}

void AdjacencyList::findOriginCity(const DSString &originCity) {
    for (iter = originCities.begin(); iter <= originCities.end(); iter.operator++()) {
        if (originCities.at(iter).getOriginName() == originCity)
            return;
    }
    iter = nullptr;
}
