//
// Created by Jack Easton on 3/26/2020.
//

#ifndef S20_PA04_FLIGHTPLANNER_STACK_H
#define S20_PA04_FLIGHTPLANNER_STACK_H

#include "LinkList.h"


template <typename T>
class Stack {
private:
    LinkList<T> stack;
public:
    Stack();

    Stack<T> & operator=(const Stack<T> &);

    void push_back(const T &val) { stack.push_back(val); }
    void pop_back() { stack.pop_back(); }
    bool isEmpty() { return stack.isEmpty(); }
    bool contains(const T &val) { return stack.contains(val); }

    T & getBack() { return stack.getBack(); }
    int getSize() { return stack.getSize(); }
    LinkList<T> & getList() { return stack; }
};

template<typename T>
Stack<T>::Stack() {
    stack = * new LinkList<T>();
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
    this->stack = rhs.stack;
}


#endif //S20_PA04_FLIGHTPLANNER_STACK_H
