#ifndef BigReal_BIGREAL_H
#define BigReal_BIGREAL_H
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;
class BigReal {
private:
    char sign ;
    string integer, fraction;
public:
    BigReal ();
    BigReal(string);
    bool IS_VALID(string number);
    bool operator < (BigReal Another_Real_Num);
    bool operator > (BigReal Another_Real_Num);
    bool operator == (BigReal Another_Real_Num);
    BigReal operator +(BigReal &Another_Real_Num);
    BigReal operator -(BigReal &Another_Real_Num);
    friend istream& operator >> (istream& in, BigReal& num);
    friend ostream& operator << (ostream& out, BigReal& num);
    void print();
};
#endif
