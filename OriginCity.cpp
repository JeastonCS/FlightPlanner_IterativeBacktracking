//
// Created by Jack Easton on 3/26/2020.
//

#include "OriginCity.h"
#include "LinkList.h"
#include "LinkListIterator.h"
#include <iostream>
using namespace std;

OriginCity::OriginCity()
{
    originName = "";
    destinations = * new LinkList<DestinationCity>;
    destinationsIter = * new LinkListIterator<DestinationCity>;
}

OriginCity::OriginCity(const DSString &name, const DestinationCity &firstDestination)
{
    originName = name;

    destinations = * new LinkList<DestinationCity>;
    destinationsIter = * new LinkListIterator<DestinationCity>;
    destinations.push_back(firstDestination);
}

OriginCity::OriginCity(const OriginCity &toCopy)
{
    originName = toCopy.originName;
    destinations = toCopy.destinations;
    destinationsIter = toCopy.destinationsIter;
}

bool OriginCity::operator==(const OriginCity &rhs)
{
    return originName == rhs.originName;
}

void OriginCity::addDestination(const DestinationCity &destination)
{
    destinations.push_back(destination);
}

DestinationCity *OriginCity::findDestination(const DSString &toFind) {
    for (auto iter = destinations.begin(); iter <= destinations.end(); iter.operator++()) {
        if (destinations.at(iter).getDestination() == toFind) {
            return &destinations.at(iter);
        }
    }
    return nullptr;
}

void OriginCity::print()
{
    cout << originName << " -> ";
    for (auto iter = destinations.begin(); iter <= destinations.end(); iter.operator++()) {
        cout << destinations.at(iter).getDestination() << " (" << destinations.at(iter).getCost() << "," << destinations.at(iter).getTime() << ") -> ";
    }
}
