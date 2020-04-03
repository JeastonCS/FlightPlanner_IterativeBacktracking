//
// Created by Jack Easton on 3/26/2020.
//

#include "OriginCity.h"
#include "LinkList.h"
#include "LinkListIterator.h"
#include <iostream>
using namespace std;

OriginCity::OriginCity() {
    originName = "";
    destinations = * new LinkList<DSString>;
    destinationsIter = * new LinkListIterator<DSString>;
    costList = * new LinkList<int>;
    timeList = * new LinkList<int>;
    costIterator = * new LinkListIterator<int>;
    timeIterator = * new LinkListIterator<int>;
}

OriginCity::OriginCity(const DSString &name) {
    originName = name;
    destinations = * new LinkList<DSString>;
    destinationsIter = * new LinkListIterator<DSString>;
    costList = * new LinkList<int>;
    timeList = * new LinkList<int>;
    costIterator = * new LinkListIterator<int>;
    timeIterator = * new LinkListIterator<int>;
}

OriginCity::OriginCity(const DSString &name, const DSString &firstDestination, int cost, int time) {
    originName = name;

    destinations = * new LinkList<DSString>;
    destinations.push_back(firstDestination);
    destinationsIter = * new LinkListIterator<DSString>;

    costList = * new LinkList<int>;
    costList.push_back(cost);
    costIterator = * new LinkListIterator<int>;

    timeList = * new LinkList<int>;
    timeList.push_back(time);
    timeIterator = * new LinkListIterator<int>;
}

OriginCity::OriginCity(const OriginCity &toCopy) {
    originName = toCopy.originName;
    destinations = toCopy.destinations;
    destinationsIter = toCopy.destinationsIter;
    costList = toCopy.costList;
    costIterator = toCopy.costIterator;
    timeList = toCopy.timeList;
    timeIterator = toCopy.timeIterator;
}

bool OriginCity::operator==(const OriginCity &rhs) const {
    return originName == rhs.originName;
}

void OriginCity::addDestination(const DSString &destination, int cost, int time) {
    destinations.push_back(destination);
    costList.push_back(cost);
    timeList.push_back(time);
}

bool OriginCity::containsDestination(const DSString &destination) {
    return destinations.contains(destination);
}

void OriginCity::print() {
    cout << originName << " --> ";
    auto cIter = costList.begin(), tIter = timeList.begin();
    for (auto iter = destinations.begin(); iter <= destinations.end(); iter.operator++()) {

        cout << destinations.at(iter) << " (" << costList.at(cIter) << ", " << timeList.at(tIter) << ") " << " --> ";

        cIter.operator++();
        tIter.operator++();
    }
    cout << endl;
}
