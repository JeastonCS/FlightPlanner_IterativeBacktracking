cmake_minimum_required(VERSION 3.14)
project(S20-PA04-FlightPlanner)
set (EXE_NAME FlightPlanner)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "FlightData.txt")
set (input02 "RequestedFlights.txt")
set (input03 "")
set (input04 "")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} catch.hpp tester.cpp main.cpp DSString.h DSString.cpp DSVector.h ListNode.h LinkList.h LinkListIterator.h Stack.h AdjacencyList.h AdjacencyList.cpp OriginCity.h OriginCity.cpp Flight.h Flight.cpp Path.h Path.cpp DestinationCity.cpp DestinationCity.h FlightPlanner.cpp FlightPlanner.h)
