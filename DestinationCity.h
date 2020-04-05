//
// Created by Jack Easton on 4/5/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_DESTINATIONCITY_H
#define S20_PA04_FLIGHTPLANNER_DESTINATIONCITY_H

#include "DSString.h"

class DestinationCity {
private:
    DSString    destination;
    int         cost;
    int         time;
public:
    DestinationCity();
    DestinationCity(const DSString &, int, int);
    DestinationCity(const DestinationCity &);

    DestinationCity &   operator=(const DestinationCity &);
    bool                operator==(const DestinationCity &rhs) { return destination == rhs.destination; }

    const DSString &    getDestination()    { return destination; }
    int                 getCost()           { return cost; }
    int                 getTime()           { return time; }
};


#endif //S20_PA04_FLIGHTPLANNER_DESTINATIONCITY_H
