//#define CATCH_CONFIG_RUNNER
//#include "catch.hpp"

#include "AdjacencyList.h"
#include "FlightPlanner.h"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){

//    if (argc == 1) {
//        Catch::Session().run();
//    }


    //create adjacency list from file
    AdjacencyList list(argv[1]);
//    list.print();

    //plan flights based on requests
    FlightPlanner planner(list, argv[2], argv[3]);

    return 0;
}
