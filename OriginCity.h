//
// Created by Jack Easton on 3/26/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
#define S20_PA04_FLIGHTPLANNER_ORIGINCITY_H

#include "DSString.h"
#include "LinkList.h"


class OriginCity {
private:
    DSString cityName;
    LinkList<DSString> destinations;
public:
    OriginCity();
    OriginCity(DSString);


    void addDestination (DSString);

};


#endif //S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
