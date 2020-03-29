//
// Created by Jack Easton on 3/26/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_LINKLISTITERATOR_H
#define S20_PA04_FLIGHTPLANNER_LINKLISTITERATOR_H

#include "ListNode.h"


template <typename T>
class LinkListIterator {
private:
    ListNode<T> *currPosition;
    int currIndex;
public:
    LinkListIterator(ListNode<T> * = nullptr);
    ~LinkListIterator() = default;

    bool operator<=(const LinkListIterator<T> &) const;
    bool operator>=(const LinkListIterator<T> &) const;
    LinkListIterator<T> & operator=(const LinkListIterator<T> &);
    LinkListIterator<T> & operator=(ListNode<T> *);
    void operator++();
    void operator--();

    bool hasNext();
    bool hasPrevious();
    T & next();
    T & previous();

    ListNode<T> * getCurrPosition() const { return currPosition; }
    int getCurrIndex() { return currIndex; }
private:
    int findIndex(ListNode<T> *);
};

template<typename T>
LinkListIterator<T>::LinkListIterator(ListNode<T> *startingPtr) {
    currPosition = startingPtr;
    currIndex = findIndex(startingPtr);
}

template<typename T>
int LinkListIterator<T>::findIndex(ListNode<T> *startingPtr) {
    int count = 0;
    ListNode<T> *curr = startingPtr;
    while (curr != nullptr) {
        count++;
        curr = curr->getPrevious();
    }
    return count - 1;
}

template<typename T>
bool LinkListIterator<T>::operator<=(const LinkListIterator<T> &rhs) const {
    return this->currIndex <= rhs.currIndex;
}
template<typename T>
bool LinkListIterator<T>::operator>=(const LinkListIterator<T> &rhs) const {
    return this->currIndex >= rhs.currIndex;
}

template<typename T>
LinkListIterator<T> &LinkListIterator<T>::operator=(const LinkListIterator<T> &rhs) {
    currPosition = rhs.currPosition;
    currIndex = rhs.currIndex;
    return *this;
}

template<typename T>
LinkListIterator<T> &LinkListIterator<T>::operator=(ListNode<T> *) {
    currPosition = nullptr;
    currIndex = -1;
    return *this;
}

template<typename T>
void LinkListIterator<T>::operator++() {
    currIndex++;
    currPosition = currPosition->getNext();
}

template<typename T>
void LinkListIterator<T>::operator--() {
    currIndex--;
    currPosition = currPosition->getPrevious();
}

template<typename T>
bool LinkListIterator<T>::hasNext() {
    return currPosition != nullptr;
}

template<typename T>
T & LinkListIterator<T>::next() {
    T *dataPtr = &currPosition->getData();
    currPosition = currPosition->getNext();
    currIndex++;
    return *dataPtr;
}

template<typename T>
bool LinkListIterator<T>::hasPrevious() {
    return currPosition != nullptr;
}

template<typename T>
T &LinkListIterator<T>::previous() {
    T *dataPtr = &currPosition->getData();
    currPosition = currPosition->getPrevious();
    currIndex--;
    return *dataPtr;
}


#endif //S20_PA04_FLIGHTPLANNER_LINKLISTITERATOR_H
