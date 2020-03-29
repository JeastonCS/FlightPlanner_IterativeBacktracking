//
// Created by Jack Easton on 3/28/2020.
//

#include "Path.h"

Path::Path() {
    path = * new LinkList<DSString>;
    cost = 0;
    time = 0;
}

Path::Path(const LinkList<DSString> &path, double cost, int time) {
    this->path = path;
    this->cost = cost;
    this->time = time;
}
