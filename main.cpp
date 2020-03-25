#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv){
    if (argc == 1) {
        Catch::Session().run();
    }

    cout << "hello world" << endl;
    return 0;
}
