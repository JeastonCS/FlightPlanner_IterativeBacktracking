//
// Created by Jack Easton on 4/5/2020.
//

#include "DestinationCity.h"

DestinationCity::DestinationCity()
{
    destination = "";
    cost = 0;
    time = 0;
}

DestinationCity::DestinationCity(const DSString &dest, int c, int t)
{
    destination = dest;
    cost = c;
    time = t;
}

DestinationCity::DestinationCity(const DestinationCity &toCopy)
{
    destination = toCopy.destination;
    cost = toCopy.cost;
    time = toCopy.time;
}

DestinationCity &DestinationCity::operator=(const DestinationCity &rhs)
{
    destination = rhs.destination;
    cost = rhs.cost;
    time = rhs.time;
    return *this;
}
