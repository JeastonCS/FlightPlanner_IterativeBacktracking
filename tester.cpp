////
//// Created by Jack Easton on 3/25/2020.
////
//
//#include "catch.hpp"
//
//#include "DSString.h"
//#include "ListNode.h"
//#include "LinkList.h"
//#include "LinkListIterator.h"
//
//TEST_CASE ("ListNode class") {
//    SECTION ("constructor (int)") {
//        ListNode<int> node1(1);
//
//        REQUIRE( node1.getData() == 1 );
//        REQUIRE( node1.getNext() == nullptr );
//        REQUIRE( node1.getPrevious() == nullptr );
//    }
//    SECTION ("setters (int)") {
//        ListNode<int> node1(1);
//        ListNode<int> next(2);
//        ListNode<int> previous(0);
//
//        node1.setNext(&next);
//        node1.setPrevious(&previous);
//
//        REQUIRE( *node1.getNext() == next );
//        REQUIRE( *node1.getPrevious() == previous );
//    }
//    SECTION ("constructor (DSString)") {
//        ListNode<DSString> node1( "test" );
//
//        REQUIRE( node1.getData() == "test" );
//        REQUIRE( node1.getNext() == nullptr );
//        REQUIRE( node1.getPrevious() == nullptr );
//    }
//    SECTION ("setters (DSString)") {
//        ListNode<DSString> node1("during");
//        ListNode<DSString> next("after");
//        ListNode<DSString> previous("before");
//
//        node1.setNext(&next);
//        node1.setPrevious(&previous);
//
//        REQUIRE( *node1.getNext() == next );
//        REQUIRE( *node1.getPrevious() == previous );
//    }
//}
//
//TEST_CASE ("LinkList class") {
//    SECTION ("constructor (int)") {
//        LinkList<int> list1;
//
//        REQUIRE( list1.getSize() == 0 );
//        REQUIRE( list1.getHead() == nullptr );
//        REQUIRE( list1.getTail() == nullptr );
//    }
//    SECTION("push_back() / push_front() (int)") {
//        LinkList<int> list1;
//
//        list1.push_front(3);
//        REQUIRE( list1.getSize() == 1 );
//        REQUIRE( list1.getFront() == 3 );
//        REQUIRE( list1.getBack() == 3 );
//
//        list1.push_front(2);
//        REQUIRE( list1.getSize() == 2 );
//        REQUIRE( list1.getFront() == 2 );
//        REQUIRE( list1.getBack() == 3 );
//
//        LinkList<int> list2;
//        list2.push_back(2);
//        REQUIRE( list2.getSize() == 1 );
//        REQUIRE( list2.getFront() == 2 );
//        REQUIRE( list2.getBack() == 2 );
//
//        list2.push_back(3);
//        REQUIRE( list2.getSize() == 2 );
//        REQUIRE( list2.getFront() == 2 );
//        REQUIRE( list2.getBack() == 3 );
//
//        //back to list 1
//        list1.push_back(4);
//        REQUIRE( list1.getSize() == 3 );
//        REQUIRE( list1.getFront() == 2 );
//        REQUIRE( list1.getBack() == 4 );
//
//        list1.push_front(1);
//        REQUIRE( list1.getSize() == 4);
//        REQUIRE( list1.getFront() == 1 );
//        REQUIRE( list1.getBack() == 4 );
//    }
//    SECTION ("operator= (int)") {
//        LinkList<int> list1;
//        list1.push_back(1);
//        list1.push_back(2);
//        list1.push_back(3);
//        list1.push_back(4);
//
//        LinkList<int> list2;
//
//        list2 = list1;
//        REQUIRE( list2.getSize() == 4 );
//        REQUIRE( list2.getFront() == 1 );
//        REQUIRE( list2.getHead()->getNext()->getData() == 2 );
//        REQUIRE( list2.getTail()->getPrevious()->getData() == 3 );
//        REQUIRE( list2.getBack() == 4 );
//
//        LinkList<int> list3;
//        list3.push_back(119);
//        list3.push_back(221);
//        list3.push_back(329);
//
//        list3 = list1;
//        REQUIRE( list3.getSize() == 4 );
//        REQUIRE( list3.getFront() == 1 );
//        REQUIRE( list3.getHead()->getNext()->getData() == 2 );
//        REQUIRE( list3.getTail()->getPrevious()->getData() == 3 );
//        REQUIRE( list3.getBack() == 4 );
//
//        LinkList<int> list4;
//        LinkList<int> list5;
//        list5.push_back(9);
//
//        list4 = list5 = list1;
//        REQUIRE( list4.getSize() == 4 );
//        REQUIRE( list4.getFront() == 1 );
//        REQUIRE( list4.getHead()->getNext()->getData() == 2 );
//        REQUIRE( list4.getTail()->getPrevious()->getData() == 3 );
//        REQUIRE( list4.getBack() == 4 );
//
//        REQUIRE( list5.getSize() == 4 );
//        REQUIRE( list5.getFront() == 1 );
//        REQUIRE( list5.getHead()->getNext()->getData() == 2 );
//        REQUIRE( list5.getTail()->getPrevious()->getData() == 3 );
//        REQUIRE( list5.getBack() == 4 );
//    }
//    SECTION("pop_front/pop_back (int)") {
//        LinkList<int> list1;
//        list1.pop_back();
//        list1.pop_front();
//
//        list1.push_back(1);
//        list1.pop_front();
//        REQUIRE(list1.getSize() == 0);
//        REQUIRE(list1.getHead() == nullptr);
//        REQUIRE(list1.getTail() == nullptr);
//
//        list1.push_back(1);
//        list1.pop_back();
//        REQUIRE(list1.getSize() == 0);
//        REQUIRE(list1.getHead() == nullptr);
//        REQUIRE(list1.getTail() == nullptr);
//
//        list1.push_back(1);
//        list1.push_back(2);
//        list1.push_back(3);
//
//        list1.pop_front();
//        REQUIRE(list1.getSize() == 2);
//        REQUIRE(list1.getFront() == 2);
//        REQUIRE(list1.getBack() == 3);
//        REQUIRE(list1.getHead()->getPrevious() == nullptr);
//        REQUIRE(list1.getHead()->getNext()->getData() == 3);
//
//        list1.push_front(1);
//        list1.pop_back();
//        REQUIRE(list1.getSize() == 2);
//        REQUIRE(list1.getFront() == 1);
//        REQUIRE(list1.getBack() == 2);
//        REQUIRE(list1.getTail()->getNext() == nullptr);
//        REQUIRE(list1.getTail()->getPrevious()->getData() == 1);
//    }
//    SECTION("contains() (int)") {
//        LinkList<int> list1;
//        bool found;
//
//        found = list1.contains(3);
//        REQUIRE(found == false);
//
//
//        list1.push_back(1);
//        found = list1.contains(1);
//        REQUIRE(found == true);
//
//
//        list1.push_back(2);
//        found = list1.contains(1);
//        REQUIRE(found == true);
//
//        found = list1.contains(2);
//        REQUIRE(found == true);
//
//        found = list1.contains(3);
//        REQUIRE(found == false);
//
//
//        list1.push_front(18);
//        list1.push_back(29);
//
//        found = list1.contains(2);
//        REQUIRE(found == true);
//
//        found = list1.contains(18);
//        REQUIRE(found == true);
//
//        found = list1.contains(29);
//        REQUIRE(found == true);
//
//        found = list1.contains(-1);
//        REQUIRE(found == false);
//
//
//        list1.pop_back();
//        found = list1.contains(29);
//        REQUIRE(found == false);
//
//        found = list1.contains(2);
//        REQUIRE(found == true);
//    }
////--------------------------------------------------------------------------------------------------------------------//
//    SECTION ("constructor (DSString)") {
//        LinkList<DSString> list1;
//
//        REQUIRE( list1.getSize() == 0 );
//        REQUIRE( list1.getHead() == nullptr );
//        REQUIRE( list1.getTail() == nullptr );
//    }
//    SECTION("push_back() / push_front() (DSString)") {
//        LinkList<DSString> list1;
//
//        list1.push_front("c");
//        REQUIRE( list1.getSize() == 1 );
//        REQUIRE( list1.getFront() == "c" );
//        REQUIRE( list1.getBack() == "c" );
//
//        list1.push_front("b");
//        REQUIRE( list1.getSize() == 2 );
//        REQUIRE( list1.getFront() == "b" );
//        REQUIRE( list1.getBack() == "c" );
//
//        LinkList<DSString> list2;
//        list2.push_back("b");
//        REQUIRE( list2.getSize() == 1 );
//        REQUIRE( list2.getFront() == "b" );
//        REQUIRE( list2.getBack() == "b" );
//
//        list2.push_back("c");
//        REQUIRE( list2.getSize() == 2 );
//        REQUIRE( list2.getFront() == "b" );
//        REQUIRE( list2.getBack() == "c" );
//
//
//
//        list1.push_back("d");
//        REQUIRE( list1.getSize() == 3 );
//        REQUIRE( list1.getFront() == "b" );
//        REQUIRE( list1.getBack() == "d" );
//
//        list1.push_front("a");
//        REQUIRE( list1.getSize() == 4);
//        REQUIRE( list1.getFront() == "a" );
//        REQUIRE( list1.getBack() == "d" );
//    }
//    SECTION ("operator= (DSString)") {
//        LinkList<DSString> list1;
//        list1.push_back("a");
//        list1.push_back("b");
//        list1.push_back("c");
//        list1.push_back("d");
//
//        LinkList<DSString> list2;
//
//        list2 = list1;
//        REQUIRE( list2.getSize() == 4 );
//        REQUIRE( list2.getFront() == "a" );
//        REQUIRE( list2.getHead()->getNext()->getData() == "b" );
//        REQUIRE( list2.getTail()->getPrevious()->getData() == "c" );
//        REQUIRE( list2.getBack() == "d" );
//
//        LinkList<DSString> list3;
//        list3.push_back("x");
//        list3.push_back("y");
//        list3.push_back("z");
//
//        list3 = list1;
//        REQUIRE( list3.getSize() == 4 );
//        REQUIRE( list2.getFront() == "a" );
//        REQUIRE( list2.getHead()->getNext()->getData() == "b" );
//        REQUIRE( list2.getTail()->getPrevious()->getData() == "c" );
//        REQUIRE( list2.getBack() == "d" );
//
//        LinkList<DSString> list4;
//        LinkList<DSString> list5;
//        list5.push_back("h");
//
//        list4 = list5 = list1;
//        REQUIRE( list4.getSize() == 4 );
//        REQUIRE( list2.getFront() == "a" );
//        REQUIRE( list2.getHead()->getNext()->getData() == "b" );
//        REQUIRE( list2.getTail()->getPrevious()->getData() == "c" );
//        REQUIRE( list2.getBack() == "d" );
//
//        REQUIRE( list5.getSize() == 4 );
//        REQUIRE( list2.getFront() == "a" );
//        REQUIRE( list2.getHead()->getNext()->getData() == "b" );
//        REQUIRE( list2.getTail()->getPrevious()->getData() == "c" );
//        REQUIRE( list2.getBack() == "d" );
//    }
//    SECTION("pop_front/pop_back (DSString)") {
//        LinkList<DSString> list1;
//        list1.pop_back();
//        list1.pop_front();
//
//        list1.push_back("a");
//        list1.pop_front();
//        REQUIRE(list1.getSize() == 0);
//        REQUIRE(list1.getHead() == nullptr);
//        REQUIRE(list1.getTail() == nullptr);
//
//        list1.push_back("a");
//        list1.pop_back();
//        REQUIRE(list1.getSize() == 0);
//        REQUIRE(list1.getHead() == nullptr);
//        REQUIRE(list1.getTail() == nullptr);
//
//        list1.push_back("a");
//        list1.push_back("b");
//        list1.push_back("c");
//
//        list1.pop_front();
//        REQUIRE(list1.getSize() == 2);
//        REQUIRE(list1.getFront() == "b");
//        REQUIRE(list1.getBack() == "c");
//        REQUIRE(list1.getHead()->getPrevious() == nullptr);
//        REQUIRE(list1.getHead()->getNext()->getData() == "c");
//
//        list1.push_front("a");
//        list1.pop_back();
//        REQUIRE(list1.getSize() == 2);
//        REQUIRE(list1.getFront() == "a");
//        REQUIRE(list1.getBack() == "b");
//        REQUIRE(list1.getTail()->getNext() == nullptr);
//        REQUIRE(list1.getTail()->getPrevious()->getData() == "a");
//    }
//    SECTION("isEmpty (both)") {
//        LinkList<int> intList;
//        LinkList<DSString> stringList;
//
//        REQUIRE(intList.isEmpty());
//        REQUIRE(stringList.isEmpty());
//
//        intList.push_back(3);
//        REQUIRE(!intList.isEmpty());
//
//        stringList.push_back("a");
//        REQUIRE(!stringList.isEmpty());
//
//        intList.pop_back();
//        REQUIRE(intList.isEmpty());
//
//        stringList.pop_back();
//        REQUIRE(stringList.isEmpty());
//    }
//    //----------------------------------------------------------------------------------------------------------------//
//    SECTION("Iterable functionality (int)") {
//        LinkList<int> list;
//        LinkListIterator<int> iter;
//
//        REQUIRE(iter.getCurrIndex() == -1);
//        REQUIRE(iter.getCurrPosition() == nullptr);
//
//        list.push_back(1);
//
//        iter = list.begin();
//        REQUIRE(iter.getCurrPosition()->getData() == 1);
//        REQUIRE(iter.getCurrIndex() == 0);
//
//        iter = list.end();
//        REQUIRE(iter.getCurrPosition()->getData() == 1);
//        REQUIRE(iter.getCurrIndex() == 0);
//
//        list.push_back(2);
//        list.push_back(3);
//        list.push_back(4);
//
//        iter = list.begin();
//        REQUIRE(iter.getCurrPosition()->getData() == 1);
//        REQUIRE(iter.getCurrIndex() == 0);
//
//        iter = list.end();
//        REQUIRE(iter.getCurrPosition()->getData() == 4);
//        REQUIRE(iter.getCurrIndex() == 3);
//
//        //written out for loop - backwards
//        iter = list.end();
//        REQUIRE(list.at(iter) == 4);
//
//        iter.operator--();
//        REQUIRE(list.at(iter) == 3);
//
//        iter.operator--();
//        REQUIRE(list.at(iter) == 2);
//
//        iter.operator--();
//        REQUIRE(iter >= list.begin());
//        REQUIRE(list.at(iter) == 1);
//
//        iter.operator--();
//
//        REQUIRE( !(iter >= list.begin()) );
//
//        //written out for loop - forwards
//        iter = list.begin();
//        REQUIRE(list.at(iter) == 1);
//
//        iter.operator++();
//        REQUIRE(list.at(iter) == 2);
//
//        iter.operator++();
//        REQUIRE(list.at(iter) == 3);
//
//        iter.operator++();
//        REQUIRE(iter <= list.end());
//        REQUIRE(list.at(iter) == 4);
//
//        iter.operator++();
//
//        REQUIRE( !(iter <= list.end()) );
//
//        //next/hasNext
//        iter = list.begin();
//        REQUIRE(iter.hasNext());
//        iter = list.end();
//        iter.operator++();
//        REQUIRE(!iter.hasNext());
//
//        iter = list.begin();
//        REQUIRE(iter.next() == 1);
//        REQUIRE(iter.next() == 2);
//        REQUIRE(iter.next() == 3);
//        REQUIRE(iter.hasNext());
//        REQUIRE(iter.next() == 4);
//
//        //previous/hasPrevious
//        iter = list.end();
//        REQUIRE(iter.hasPrevious());
//        iter = list.begin();
//        iter.operator--();
//        REQUIRE(!iter.hasPrevious());
//
//        iter = list.end();
//        REQUIRE(iter.previous() == 4);
//        REQUIRE(iter.previous() == 3);
//        REQUIRE(iter.previous() == 2);
//        REQUIRE(iter.hasPrevious());
//        REQUIRE(iter.previous() == 1);
//    }
//    SECTION("Iterable functionality (DSString)") {
//        LinkList<DSString> list;
//        LinkListIterator<DSString> iter;
//
//        REQUIRE(iter.getCurrIndex() == -1);
//        REQUIRE(iter.getCurrPosition() == nullptr);
//
//        list.push_back("1");
//
//        iter = list.begin();
//        REQUIRE(iter.getCurrPosition()->getData() == "1");
//        REQUIRE(iter.getCurrIndex() == 0);
//
//        iter = list.end();
//        REQUIRE(iter.getCurrPosition()->getData() == "1");
//        REQUIRE(iter.getCurrIndex() == 0);
//
//        list.push_back("2");
//        list.push_back("3");
//        list.push_back("4");
//
//        iter = list.begin();
//        REQUIRE(iter.getCurrPosition()->getData() == "1");
//        REQUIRE(iter.getCurrIndex() == 0);
//
//        iter = list.end();
//        REQUIRE(iter.getCurrPosition()->getData() == "4");
//        REQUIRE(iter.getCurrIndex() == 3);
//
//        //written out for loop - backwards
//        iter = list.end();
//        REQUIRE(list.at(iter) == "4");
//
//        iter.operator--();
//        REQUIRE(list.at(iter) == "3");
//
//        iter.operator--();
//        REQUIRE(list.at(iter) == "2");
//
//        iter.operator--();
//        REQUIRE(iter >= list.begin());
//        REQUIRE(list.at(iter) == "1");
//
//        iter.operator--();
//
//        REQUIRE( !(iter >= list.begin()) );
//
//        //written out for loop - forwards
//        iter = list.begin();
//        REQUIRE(list.at(iter) == "1");
//
//        iter.operator++();
//        REQUIRE(list.at(iter) == "2");
//
//        iter.operator++();
//        REQUIRE(list.at(iter) == "3");
//
//        iter.operator++();
//        REQUIRE(iter <= list.end());
//        REQUIRE(list.at(iter) == "4");
//
//        iter.operator++();
//
//        REQUIRE( !(iter <= list.end()) );
//
//        //next/hasNext
//        iter = list.begin();
//        REQUIRE(iter.hasNext());
//        iter = list.end();
//        iter.operator++();
//        REQUIRE(!iter.hasNext());
//
//        iter = list.begin();
//        REQUIRE(iter.next() == "1");
//        REQUIRE(iter.next() == "2");
//        REQUIRE(iter.next() == "3");
//        REQUIRE(iter.hasNext());
//        REQUIRE(iter.next() == "4");
//
//        //previous/hasPrevious
//        iter = list.end();
//        REQUIRE(iter.hasPrevious());
//        iter = list.begin();
//        iter.operator--();
//        REQUIRE(!iter.hasPrevious());
//
//        iter = list.end();
//        REQUIRE(iter.previous() == "4");
//        REQUIRE(iter.previous() == "3");
//        REQUIRE(iter.previous() == "2");
//        REQUIRE(iter.hasPrevious());
//        REQUIRE(iter.previous() == "1");
//    }
//}