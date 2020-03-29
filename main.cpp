#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "DSString.h"
#include "LinkList.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

    if (argc == 1) {
        Catch::Session().run();
    }

    //create adjacency list from file

    //create vector of flights from file

    //loop through vector of flights and call backtrackPossiblePaths(w/ ^list) AND getTopThreePaths() on each Flight in vector


    return 0;
}
