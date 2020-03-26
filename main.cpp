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


//    LinkList<int> list1;
//    list1.push_back(1);
//    list1.push_back(2);
//    list1.push_back(3);
//    list1.push_back(4);
//
//    LinkList<int> list2;
//
//    list2 = list1;
//    int temp = list2.getSize();
//    cout << temp << endl;


    return 0;
}
