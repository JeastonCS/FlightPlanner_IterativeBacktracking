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

    LinkList & operator= (const LinkList &);


    void push_front(ListNode<T> &);
    void push_back(ListNode<T> &);
    ListNode<T> & pop_front();
    ListNode<T> & pop_back();
    bool isEmpty();
    bool contains(const ListNode<T> &);

    int getSize();
    ListNode<T> & getFront();
    ListNode<T> & getBack();

};

#endif //S20_PA04_FLIGHTPLANNER_LINKLIST_H
