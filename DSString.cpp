#include "DSString.h"
//#include "DSVector.h"

#include <cctype>
#include <cmath>
#include <cstring>

//--------------------------------------------------- Constructors ---------------------------------------------------//

/* no parameter */
DSString::DSString() {
    data_ = new char[1];
    data_[0] = '\0';
}

/* c-string */
DSString::DSString(const char *startingData) {
    data_ = new char[strlen(startingData) + 1];
    strcpy(data_, startingData);
}

/* copy constructor */
DSString::DSString(const DSString &startingString) {
    data_ = new char[strlen(startingString.data_) + 1];
    strcpy(data_, startingString.data_);
}

/* destructor */
DSString::~DSString() {
    delete [] data_;
}

//----------------------------------------------- Overloaded Operators -----------------------------------------------//

/* assignment operator */
DSString &DSString::operator=(const char *rhs) {
    delete [] data_;
    data_ = nullptr;

    const int length = strlen(rhs);

    data_ = new char[length + 1];
    strcpy(data_, rhs);
    data_[length] = '\0';

    return *this;
}
DSString &DSString::operator=(const DSString &rhs) {
    *this = rhs.data_;
    return *this;
}

/* comparison operator */
bool DSString::operator==(const char *rhs) const {
    return strcmp(this->data_, rhs) == 0;
}
bool DSString::operator==(const DSString &rhs) const {
    return *this == rhs.data_;
}

/* plus operator */
DSString DSString::operator+(const char *rhs) {
    char *temp = new char[strlen(this->data_) + strlen(rhs) + 1];

    strcpy(temp, this->data_);
    strcat(temp, rhs);

    DSString sumString;
    sumString = temp;
    delete [] temp;

    return sumString;
}
DSString DSString::operator+(const DSString &rhs) {
    return *this + rhs.data_;
}

/* plus-equals operator */
void DSString::operator+=(const char *rhs) {
    *this = *this + rhs;
}
void DSString::operator+=(const DSString &rhs) {
    *this = *this + rhs;
}
void DSString::operator+=(char c) {
    int length = strlen(data_);

    char *temp = new char[length + 2]; //1 for null terminator, 1 for new char
    strcpy(temp, data_);
    temp[length] = c;
    temp[length + 1] = '\0';

    delete [] data_;
    data_ = temp;
}

/* less-than operator */
bool DSString::operator<(const DSString &rhs) const {
    return strcmp(data_, rhs.data_) < 0;
}

/* greater-than operator */
bool DSString::operator>(const DSString &rhs) const {
    return strcmp(data_, rhs.data_) > 0;
}

/* insertion operator */
ostream &operator<<(ostream &os, const DSString &dsString) {
    os << dsString.data_;
    return os;
}

//-------------------------------------------------- Public Methods --------------------------------------------------//

/* return the DSString from starting index to end of this DSString */
DSString& DSString::substring(int startIndex) {
    return substring(startIndex, strlen(data_));
}

/* return the DSString within the given bounds (inclusive, exclusive) */
DSString& DSString::substring(int startIndex, int endIndex) {
    int length = endIndex - startIndex;
    char* temp = new char[length + 1];

    for(int i = 0; i < length; i++)
        temp[i] = data_[i + startIndex];
    temp[length] = '\0';

    DSString *sub = new DSString(temp);
    delete [] temp;
    return *sub;
}

/* locate a single character within this DSString
 * return the index of that char or -1 if not found */
int DSString::findChar(char character, int startIndex) {
    int len = strlen(data_);
    for(int i = startIndex; i < len; i++) {
        if(data_[i] == character)
            return i;
    }
    return -1;
}

/* locate a DSString withing this DSString
 * return the index of its first character or -1 if not found. */
int DSString::findDSString(const DSString &sub, int startIndex) {
    int len = strlen(data_);
    int subLen = strlen(sub.data_);

    bool found = false;

    int index = -1;
    int j;
    int i;
    for (i = startIndex, j = 0; i < len; i++) {
        if (j == subLen) {
            return index;
        }
        if ( data_[i] == sub.data_[j] ) {
            if (!found) {
                index = i;
                found = true;
                j++;
            }
            else
                j++;
        }
        else {
            if (found) {
                found = false;
                j = 0;
            }
        }
    }
    if (j == subLen) {
        return index;
    }
    return -1; //should return -1 (sub not found)
}

/* divides this DSString into a vector of strings based on delimiter parameter */
//DSVector<DSString> DSString::toVector(char delimiter) {
//    DSVector<DSString> words;
//    int length = strlen(data_);
//
//    DSString temp = "";
//
//    bool onDelim = true;
//    for (int i = 0; i < length; i++) {
//        if(data_[i] == delimiter) {
//            if(onDelim == false) {
//                words.push_back(temp);
//                temp = "";
//            }
//            onDelim = true;
//        }
//        else {
//            temp += data_[i];
//            onDelim = false;
//        }
//    }
//    if( !(temp == "") ) {
//        temp += '\0';
//        words.push_back(temp);
//    }
//
//    return words;
//}

/* changes all characters to lowercase */
void DSString::toLower() {
    int length = strlen(data_);

    char *temp = new char[length + 1];
    int i;
    for (i = 0; i < length; i++) {
        if (isupper(data_[i]))
            temp[i] = tolower(data_[i]);
        else
            temp[i] = data_[i];
    }
    temp[i] = '\0';

    delete [] data_;
    data_ = temp;
}
void DSString::removePunct() {
    int length = strlen(data_);

    char *temp = new char[length + 1];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (!( data_[i] == ',' || data_[i] == '!' || data_[i] == '.' || data_[i] == '?' || data_[i] == ':' || data_[i] == ';' || data_[i] == '\'' || data_[i] == '\"' || data_[i] == '/' || data_[i] == '\\' || data_[i] == '[' || data_[i] == ']' || data_[i] == '{' || data_[i] == '}'))
            temp[j++] = data_[i];
    }
    temp[j] = '\0';

    delete [] data_;
    data_ = temp;
}

//-------------------------------------------------- Getter Methods --------------------------------------------------//

/* return the character at a certain index */
char DSString::at(int index) {
    if (index < strlen(data_))
        return data_[index];
    else {
        cout << "invalid index" << endl;
        return 0;
    }
}
