//
// Created by Jack Easton on 3/26/2020.
//

#include "OriginCity.h"
#include "LinkList.h"
#include "LinkListIterator.h"

OriginCity::OriginCity() {
    originName = "";
    destinations = * new LinkList<DSString>;
}

OriginCity::OriginCity(DSString &name) {
    originName = name;
    destinations = * new LinkList<DSString>;
}

OriginCity::OriginCity(DSString &name, DSString &firstDestination) {
    originName = name;
    destinations = * new LinkList<DSString>;
    destinations.push_back(firstDestination);
}

void OriginCity::addDestination(DSString &destination) {
    destinations.push_back(destination);
}

bool OriginCity::containsDestination(const DSString &destination) {
    return destinations.contains(destination);
}
