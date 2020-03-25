#ifndef SENTIMENTANALYSIS_DSSTRING_H
#define SENTIMENTANALYSIS_DSSTRING_H

//#include "DSVector.h"

#include <cstring>
#include <iostream>
using namespace std;

class DSString {
private:
    char *data_;
public:
    //-------------------- Constructors --------------------//
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    //---------------- Overloaded Operators ----------------//
    bool operator==(const char*) const;
    DSString& operator=(const char*);
    DSString operator+(const char*);
    void operator+=(const char*);
    void operator+=(char);

    bool operator==(const DSString&) const;
    DSString& operator=(const DSString&);
    DSString operator+(const DSString&);
    void operator+=(const DSString&);
    bool operator<(const DSString&) const;
    bool operator>(const DSString&) const;

    friend ostream& operator<<(ostream&, const DSString&);

    //------------------- Public Methods -------------------//
    DSString & substring(int);
    DSString & substring(int, int);
    int findChar(char, int = 0);
    int findDSString(const DSString &, int = 0);
    int toInt() {char *ptr = new char; return strtol(data_, &ptr, 10); }
//    DSVector<struct DSString> toVector(char);
    void toLower();
    void removePunct();

    //------------------- Getter Methods -------------------//
    void print(){ cout << data_ << endl; }
    int getLength() { return strlen(data_); }
    char at(int);
};
#endif //SENTIMENTANALYSIS_DSSTRING_H
