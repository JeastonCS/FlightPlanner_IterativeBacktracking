//
// Created by Jack Easton on 3/28/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H
#define S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H

#include "LinkList.h"
#include "LinkListIterator.h"
#include "OriginCity.h"
#include "DestinationCity.h"

#include <fstream>
using namespace std;


class AdjacencyList {
private:
    LinkList<OriginCity> originCities;
public:
    AdjacencyList();
    AdjacencyList(char *);

    AdjacencyList & operator=(const AdjacencyList &);

    OriginCity * originCityAt(const DSString &);

    void print();
private:
    void                            initializeWithFile(char *);
    void                            addOriginDestinationPair(const DSString &, const DSString &, int, int);
    LinkListIterator<OriginCity>    findOriginCity(const DSString &);
};


#endif //S20_PA04_FLIGHTPLANNER_ADJACENCYLIST_H
