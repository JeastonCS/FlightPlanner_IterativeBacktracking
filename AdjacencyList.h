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
    AdjacencyList(char *);

    AdjacencyList & operator=(const AdjacencyList &);

    void initializeWithFile(char *);
    void addOriginDestinationPair(const DSString &, const DSString &, int, int);
    void findOriginCity(const DSString &);
    OriginCity * originCityAt(const DSString &);

    void print();
};


#endif //S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H
