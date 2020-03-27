//
// Created by Jack Easton on 3/25/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_LINKLIST_H
#define S20_PA04_FLIGHTPLANNER_LINKLIST_H

#include "ListNode.h"
#include "LinkListIterator.h"

#include <iostream>
using namespace std;

template <typename T>
class LinkList {
private:
    ListNode<T> *head, *tail;
    int size;
public:
    LinkList();
    ~LinkList();

    LinkList<T> & operator= (const LinkList &);


    void push_front(const T &);
    void push_back(const T &);
    void pop_front();
    void pop_back();
    bool isEmpty();
    bool contains(const T &);

    int getSize() { return size; }
    ListNode<T> * getHead() { return head; }
    ListNode<T> * getTail() { return tail; }
    T getFront() { return head->getData(); }
    T getBack() { return tail->getData(); }

    LinkListIterator<T> & begin() { return * new LinkListIterator<T>(head); }
    LinkListIterator<T> & end() { return * new LinkListIterator<T>(tail); }
    T & at(const LinkListIterator<T> &iter) const { return iter.getCurrPosition()->getData(); } //TODO

};

template <typename T>
LinkList<T>::LinkList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkList<T>::~LinkList() {
    ListNode<T> *curr = head;
    while (curr != nullptr) {
        head = curr->getNext();
        curr->~ListNode<T>();
        curr = head;
    }
    tail = head;
}

template<typename T>
LinkList<T> & LinkList<T>::operator=(const LinkList &rhs) {
    this->~LinkList<T>();
    this->size = 0;

    ListNode<T> *curr = rhs.head;
    while (curr != nullptr) {
        this->push_back(curr->getData());
        curr = curr->getNext();
    }

    return *this;
}

template<typename T>
void LinkList<T>::push_front(const T &val) {
    this->size++;

    ListNode<T> *nodePtr = new ListNode(val);
    if (head == nullptr) {
        head = tail = nodePtr;
    }
    else {
        ListNode<T> *oldHead = head;
        head = nodePtr;
        nodePtr->setNext(oldHead);
        oldHead->setPrevious(head);
    }
}

template<typename T>
void LinkList<T>::push_back(const T &val) {
    this->size++;

    ListNode<T> *nodePtr = new ListNode(val);
    if (head == nullptr) {
        head = tail = nodePtr;
    }
    else {
        ListNode<T> *oldTail = tail;
        tail = nodePtr;
        nodePtr->setPrevious(oldTail);
        oldTail->setNext(tail);
    }
}

template<typename T>
void LinkList<T>::pop_front() {
    if (head == nullptr) {
        cout << "Attempt to remove element when list is EMPTY." << endl;
        return;
    }

    this->size--;

    ListNode<T> *oldHead = head;
    head = head->getNext();
    delete oldHead;

    if (size == 0) { //the only node (before removing) was the head and the tail
        tail = head;
    }
    else {
        head->setPrevious(nullptr);
    }
}

template<typename T>
void LinkList<T>::pop_back() {
    if (head == nullptr) {
        cout << "Attempt to remove element when list is EMPTY." << endl;
        return;
    }
    this->size--;

    ListNode<T> *oldTail = tail;
    tail = tail->getPrevious();
    delete oldTail;

    if (size == 0) { //the only node (before removing) was the head and the tail
        head = tail;
    }
    else {
        tail->setNext(nullptr);
    }
}

template<typename T>
bool LinkList<T>::isEmpty() {
    return size == 0;
}

template<typename T>
bool LinkList<T>::contains(const T &element) {
    ListNode<T> *curr = head;
    while (curr != nullptr) {
        if (curr->getData() == element)
            return true;
        curr = curr->getNext();
    }
    return false;
}

#endif //S20_PA04_FLIGHTPLANNER_LINKLIST_H
