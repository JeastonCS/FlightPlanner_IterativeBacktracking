//
// Created by Jack Easton on 3/25/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_LISTNODE_H
#define S20_PA04_FLIGHTPLANNER_LISTNODE_H

template <typename T>
class ListNode {
private:
    T data;
    ListNode *next, *previous;

public:
    ListNode() {
        next = nullptr;
        previous = nullptr;
    }
    ListNode(T val) {
        data = val;
        next = nullptr;
        previous = nullptr;
    }
    ~ListNode() {}

    bool operator==(const ListNode &rhs) const { return data == rhs.data; }

    void setNext(ListNode *ptr) { next = ptr; }
    void setPrevious(ListNode *ptr) { previous = ptr; }

    ListNode *& getNext() { return next; }
    ListNode *& getPrevious() { return previous; }
    T & getData() { return data; }
};

#endif //S20_PA04_FLIGHTPLANNER_LISTNODE_H
