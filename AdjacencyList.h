//
// Created by Jack Easton on 3/28/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H
#define S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H

#include "LinkList.h"
#include "LinkListIterator.h"
#include "OriginCity.h"


class AdjacencyList {
private:
    LinkList<OriginCity> originCities;
    LinkListIterator<OriginCity> iter;
public:
    AdjacencyList();

    AdjacencyList & operator=(const AdjacencyList &);

    void addOriginDestinationPair(DSString &, DSString &);


private:
    void findOriginCity(const DSString &);
};


#endif //S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H
