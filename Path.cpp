//
// Created by Jack Easton on 3/28/2020.
//

#include "Path.h"

Path::Path() {
    path = * new LinkList<DSString>();
    cost = 0;
    time = 0;
}

Path::Path(const Path &toCopy) {
    path = toCopy.path;
    cost = toCopy.cost;
    time = toCopy.time;
}

Path::Path(LinkList<OriginCity> &path, int cost, int time) {
    initializePath(path);
    this->cost = cost;
    this->time = time;
}

Path &Path::operator=(const Path &rhs) {
    path = rhs.path;
    cost = rhs.cost;
    time = rhs.time;

    return *this;
}

void Path::initializePath(LinkList<OriginCity> &pathOfOriginCities) {
    path = * new LinkList<DSString>;
    for (auto iter = pathOfOriginCities.begin(); iter <= pathOfOriginCities.end(); iter.operator++()) {
        path.push_back(pathOfOriginCities.at(iter).getOriginName());
    }
}
