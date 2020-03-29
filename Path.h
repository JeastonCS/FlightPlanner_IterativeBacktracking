//
// Created by Jack Easton on 3/28/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_PATH_H
#define S20_PA04_FLIGHTPLANNER_PATH_H

#include "DSString.h"
#include "DSVector.h"
#include "LinkList.h"

class Path {
private:
    LinkList<DSString> path;
    double cost;
    int time;
public:
    Path();
    Path(const LinkList<DSString> &, double, int);
};


#endif //S20_PA04_FLIGHTPLANNER_PATH_H
