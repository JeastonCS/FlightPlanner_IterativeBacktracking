//
// Created by Jack Easton on 3/25/2020.
//

#include "catch.hpp"

#include "DSString.h"
#include "ListNode.h"

TEST_CASE ("ListNode class") {
    SECTION ("constructor (int)") {
        ListNode<int> node1(1);

        REQUIRE( node1.getData() == 1 );
        REQUIRE( node1.getNext() == nullptr );
        REQUIRE( node1.getPrevious() == nullptr );
    }
    SECTION ("setters (int)") {
        ListNode<int> node1(1);
        ListNode<int> next(2);
        ListNode<int> previous(0);

        node1.setNext(&next);
        node1.setPrevious(&previous);

        REQUIRE( *node1.getNext() == next );
        REQUIRE( *node1.getPrevious() == previous );
    }
    SECTION ("constructor (DSString)") {
        DSString string1("test");
        ListNode<DSString> node1( string1 );

        REQUIRE( node1.getData() == "test" );
        REQUIRE( node1.getNext() == nullptr );
        REQUIRE( node1.getPrevious() == nullptr );
    }
    SECTION ("setters (DSString)") {
        DSString string1("during");
        DSString nextString("after");
        DSString previousString("before");

        ListNode<DSString> node1(string1);
        ListNode<DSString> next(nextString);
        ListNode<DSString> previous(previousString);

        node1.setNext(&next);
        node1.setPrevious(&previous);

        REQUIRE( *node1.getNext() == next );
        REQUIRE( *node1.getPrevious() == previous );
    }
}