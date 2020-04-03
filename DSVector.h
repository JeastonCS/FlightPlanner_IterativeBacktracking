//
// Created by Jack Easton on 2/12/2020.
//

#ifndef INC_20S_PA02_AUTOINDEXER_DSVECTOR_H
#define INC_20S_PA02_AUTOINDEXER_DSVECTOR_H

#include <stdexcept>
#include <iostream>

template <typename T>
class DSVector {
private:
    T *data_;
    int size_;
    int capacity_;
public:
    //-------------------- Constructors --------------------//
    DSVector();
    DSVector(int);
    DSVector(const DSVector<T> &);
    ~DSVector();

    //---------------- Overloaded Operators ----------------//
    DSVector operator=(const DSVector &);
    bool operator==(const DSVector &) const;
    bool operator< (const DSVector &rhs) const { return this->vectcmp(rhs) == -1; }
    bool operator> (const DSVector &rhs) const { return this->vectcmp(rhs) == 1; }
    T & operator[](int index) const { return data_[index]; }

    //------------------- Public Methods -------------------//
    void push_back(const T &);
    void push_sorted(const T &);
    void removeAt(int index);
    int vectcmp (const DSVector &) const;
    int find(const T &); //returns index where it found element or -1
    bool isEmpty() { return size_ == 0; }

    //------------------- Private Methods ------------------//
private:
    void resize();
    int findRecursion(int, int, const T &);

    //------------------- Getter Methods -------------------//
public:
    int size() { return size_; }
    int getCapacity() { return capacity_; }
    T & at(int index) const { return data_[index]; }

};

//--------------------------------------------------- Constructors ---------------------------------------------------//

/* no parameter */
template<typename T>
DSVector<T>::DSVector() {
    data_ = new T[3];
    capacity_ = 3;
    size_ = 0;
}

/* initial capacity */
template<typename T>
DSVector<T>::DSVector(int cap) {
    data_ = new T[cap];
    capacity_ = cap;
    size_ = 0;
}

/* copy constructor */
template<typename T>
DSVector<T>::DSVector(const DSVector<T> &toCopy) {
    size_ = toCopy.size_;
    capacity_ = toCopy.capacity_;

    data_ = new T[capacity_];
    for(int i = 0; i < size_; i++)
        data_[i] = toCopy.data_[i];
}

/* destructor */
template<typename T>
DSVector<T>::~DSVector() {
    delete [] data_;
}

//----------------------------------------------- Overloaded Operators -----------------------------------------------//

/* assignment operator */
template<typename T>
DSVector<T> DSVector<T>::operator=(const DSVector &rhs) {
    size_ = rhs.size_;
    capacity_ = rhs.capacity_;

    delete [] data_;
    data_ = new T[capacity_];

    for (int i = 0; i < size_; i++)
        data_[i] = rhs.data_[i];

    return *this;
}

/* comparison operator */
template<typename T>
bool DSVector<T>::operator==(const DSVector &rhs) const{
    if (size_ != rhs.size_)
        return false;

    for (int i = 0; i < size_; i++) {
        if ( !(data_[i] == rhs.data_[i]) )
            return false;
    }
    return true;
}

//-------------------------------------------------- Public Methods --------------------------------------------------//

/* add element to vector at the end of current vector */
template<typename T>
void DSVector<T>::push_back(const T &element) {
    if (size_ == capacity_)
        resize();

    data_[size_++] = element;
}

/* add element to vector in its sorted position */
template<typename T>
void DSVector<T>::push_sorted(const T &element) {
    if (size_ == capacity_)
        resize();

    T *temp = new T[capacity_];

    bool inserted = false;
    int i;
    for (i = 0; i < size_; i++) {
        if (data_[i] > element && !inserted) {
            temp[i] = element;
            inserted = true;
        }
        else
        if (inserted)
            temp[i] = data_[i - 1];
        else
            temp[i] = data_[i];
    }
    if (!inserted)
        temp[i] = element;
    else
        temp[i] = data_[i - 1];

    size_++;

    delete [] data_;
    data_ = temp;
}

template <typename T>
void DSVector<T>::removeAt(int index) {
    if (index < 0 || index >= size_)
        throw std::out_of_range("index out of range");

    T *temp = new T[size_ - 1];

    for (int i = 0, j = 0; i < size_; i ++) {
        if (i != index) {
            temp[j] = data_[i];
            j++;
        }
    }

    delete [] data_;
    data_ = temp;

    size_--;
}

/* compares two vectors
 * returns -1  if  this < right
 * returns 0   if  this == right
 * returns 1   if  this > right */
template<typename T>
int DSVector<T>::vectcmp(const DSVector &rhs) const {
    for (int i = 0; i < size_ && i < rhs.size_; i++) {
        if (data_[i] > rhs.data_[i])
            return 1;
        else if (data_[i] < rhs.data_[i])
            return -1;
    }
    if (*this == rhs)
        return 0;
    else if (size_ > rhs.size_)
        return 1;
    else
        return -1;
}

/* finds specific element in vector
 * returns index of that element or -1 if not found */
template<typename T>
int DSVector<T>::find(const T &element) {
    return findRecursion(0, size_ - 1, element);
}

//-------------------------------------------------- Private Methods -------------------------------------------------//

/* increase capacity of vector */
template<typename T>
void DSVector<T>::resize() {
    capacity_ *= 2;

    T *temp = new T[capacity_];
    for(int i = 0; i < size_; i++)
        temp[i] = data_[i];

    delete [] data_;
    data_ = temp;
}

/* recursive binary search for find method */
template<typename T>
int DSVector<T>::findRecursion(int startIndex, int endIndex, const T &key) {
    //not in vector
    if (startIndex > endIndex)
        return -1;

    //found
    int mid = (startIndex + endIndex) / 2;
    if (data_[mid] == key)
        return mid;

    //still searching... recursive calls
    if (data_[mid] > key) {
        return findRecursion(startIndex, mid - 1, key);
    }
    else
        return findRecursion(mid + 1, endIndex, key);
}


#endif //INC_20S_PA02_AUTOINDEXER_DSVECTOR_H
