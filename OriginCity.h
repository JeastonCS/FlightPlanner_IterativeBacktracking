//
// Created by Jack Easton on 3/26/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
#define S20_PA04_FLIGHTPLANNER_ORIGINCITY_H

#include "DSString.h"
#include "LinkList.h"
#include "LinkListIterator.h"


class OriginCity {
private:
    DSString originName;

    LinkList<DSString> destinations;
    LinkList<int> costList;
    LinkList<int> timeList;

    LinkListIterator<DSString> destinationsIter;
    LinkListIterator<int> costIterator;
    LinkListIterator<int> timeIterator;

public:
    OriginCity();
    OriginCity(const OriginCity &);
    OriginCity(const DSString &);
    OriginCity(const DSString &, const DSString &, int, int);

    bool operator==(const OriginCity &) const;

    void addDestination (const DSString &, int, int);
    bool containsDestination (const DSString &);
    void moveToNextDestination() { destinationsIter.operator++(); costIterator.operator++(); timeIterator.operator++(); }

    const DSString & getOriginName() const { return originName; }
    LinkListIterator<DSString> & getDestinationsIter() { return destinationsIter; }
    LinkListIterator<int> & getCostIterator() { return costIterator; }
    LinkListIterator<int> & getTimeIterator() { return timeIterator; }
    void setIterators() { destinationsIter = destinations.begin(); costIterator = costList.begin(); timeIterator = timeList.begin(); }
    LinkListIterator<DSString> & getDestinationsBegin() { return destinations.begin(); }
    LinkListIterator<int> & getCostIteratorBegin() { return costList.begin(); }
    LinkListIterator<int> & getTimeIteratorBegin() { return timeList.begin(); }
    LinkListIterator<DSString> & getDestinationsEnd() { return destinations.end(); }
    LinkListIterator<int> & getCostListEnd() { return costList.end(); }
    LinkListIterator<int> & getTimeListEnd() { return timeList.end(); }
//    LinkListIterator<int> & getCostIteratorEnd()
//    LinkListIterator<int> & get
//    LinkList<DSString> & getDestinations() { return destinations; }

    void print();

};


#endif //S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
