//
// Created by Jack Easton on 3/25/2020.
//

#include "ListNode.h"
#include "LinkList.h"

template <typename T>
LinkList<T>::LinkList() : size(0), head(nullptr), tail(nullptr) {}

template <typename T>
LinkList<T>::~LinkList() {
    ListNode<T> *curr = head;
    while (curr != nullptr) {
        head = curr->getNext();
        delete curr;
        curr = head;
    }
}