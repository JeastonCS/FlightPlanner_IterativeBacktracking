//
// Created by Jack Easton on 3/28/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_PATH_H
#define S20_PA04_FLIGHTPLANNER_PATH_H

#include "DSString.h"
#include "DSVector.h"
#include "LinkList.h"
#include "OriginCity.h"

class Path {
private:
    LinkList<DSString> path;
    int cost;
    int time;
public:
    Path();
    Path(LinkList<OriginCity> &, int, int);
    Path(const Path &);

    Path & operator=(const Path &);

    int getCost() { return cost; }
    int getTime() { return time; }
    LinkList<DSString> & getPath() { return path; }

private:
    void initializePath(LinkList<OriginCity> &);
};


#endif //S20_PA04_FLIGHTPLANNER_PATH_H
