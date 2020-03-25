#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

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
//
//
//    LinkList<int> list3;
//    list3.push_back(119);
//    list3.push_back(221);
//    list3.push_back(329);
//
//    list3 = list1;
//
//
//    LinkList<int> list4;
//    LinkList<int> list5;
//    list5.push_back(9);
//
////    list5 = list1;
////    list4 = list5;
//    list4 = list5 = list1;



    return 0;
}
