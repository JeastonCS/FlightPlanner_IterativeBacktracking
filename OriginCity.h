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
    LinkListIterator<DSString> iter;

public:
    OriginCity();
    OriginCity(DSString &);
    OriginCity(DSString &, DSString &);


    void addDestination (DSString &);
    bool containsDestination (const DSString &);

    DSString & getOriginName() { return originName; }

};


#endif //S20_PA04_FLIGHTPLANNER_ORIGINCITY_H
