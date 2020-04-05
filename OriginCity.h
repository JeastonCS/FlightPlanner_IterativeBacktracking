//
// Created by Jack Easton on 3/26/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
#define S20_PA04_FLIGHTPLANNER_ORIGINCITY_H

#include "DSString.h"
#include "LinkList.h"
#include "LinkListIterator.h"
#include "DestinationCity.h"


class OriginCity {
private:
    DSString                            originName;
    LinkList<DestinationCity>           destinations;
    LinkListIterator<DestinationCity>   destinationsIter;

public:
    OriginCity();
    OriginCity (const DSString &, const DestinationCity &);
    OriginCity (const OriginCity &);

    bool                                operator== (const OriginCity &);

    void                                addDestination (const DestinationCity &);
    void                                moveToNextDestination()                     { destinationsIter.operator++(); }

    DSString &                          getOriginName()                             { return originName; }
    DestinationCity *                   findDestination(const DSString &);
    void                                setIterators()                              { destinationsIter = destinations.begin(); }
    LinkListIterator<DestinationCity> & getDestinationsIter()                       { return destinationsIter; }
    LinkListIterator<DestinationCity> & getDestinationsBegin()                      { return destinations.begin(); }
    LinkListIterator<DestinationCity> & getDestinationsEnd()                        { return destinations.end(); }

    void print();
};


#endif //S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
