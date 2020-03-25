//
// Created by Jack Easton on 3/25/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_LINKLIST_H
#define S20_PA04_FLIGHTPLANNER_LINKLIST_H

#include "ListNode.h"

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
    ListNode<T> & pop_front();
    ListNode<T> & pop_back();
    bool isEmpty();
    bool contains(const ListNode<T> &);

    int getSize() { return size; }
    ListNode<T> * getHead() { return head; }
    ListNode<T> * getTail() { return tail; }
    T getFront() { return head->getData(); }
    T getBack() { return tail->getData(); }

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
        delete curr;
        curr = head;
    }
}

template<typename T>
LinkList<T> & LinkList<T>::operator=(const LinkList &rhs) {
    this->~LinkList<T>();

    this->size = rhs.size;
    this->head = rhs.head;
    this->tail = rhs.tail;

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

#endif //S20_PA04_FLIGHTPLANNER_LINKLIST_H
