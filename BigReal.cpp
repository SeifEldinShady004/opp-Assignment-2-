#include "BigReal.h"
using namespace std;
bool BigReal::IS_VALID(string RealNum) {
    bool valid = true;
    string num = RealNum;
    //remove the sign
    if(num[0]=='+'||num[0]=='-') {
        num.erase(0,1);
    }
    //check if '.' exists
    if(count(num.begin(), num.end(),'.') == 1&&num.find('.')!=num.npos) {
        num.erase(remove(num.begin(), num.end(),'.'),num.end());
    }
    else if(count(num.begin(), num.end(),'.') > 1 ) {
        valid = false;
    }
    if (!regex_match(num, regex("[0-9]+"))) {
        valid = false;
    }
    if (!isdigit(num[0]) && !isdigit(num[1]))
        valid = false;
    return valid;
}
BigReal::BigReal() {
        sign='+';
        integer="0";
        fraction="0";
}
BigReal::BigReal(string number) {
    //check if the number is valid
    if (IS_VALID(number)) {
        //store the sign
        if (number[0] == '+' || number[0] == '-') {
            sign = number[0];
            number.erase(number.begin());
        } else
            sign = '+';
        //store the integer part and the fraction part in all cases
        if (number.find('.') == 0) {
            integer = "0";
            fraction = number.substr(1, number.size() - 1);
        } else if (number.find('.') == number.size() - 1) {
            number.pop_back();
            integer = number;
            fraction = "0";
        }
        else if(number.find('.')){
            integer = number.substr(0,number.find('.'));
            fraction = number.substr(integer.size()+1,number.size()-1);
        }
        else if(number.find('.')==number.npos){
            integer = number;
            fraction = "0";
        }
    }
    else{
        sign = '+';
        integer = "$";
        fraction = "$";
    }
}
bool BigReal :: operator > (BigReal Another_Real_Num)
{
    // - is not greater than +
  if(this->sign == '-' && Another_Real_Num.sign == '+') {
      return false;
  }
  // + is greater than -
  else if(this->sign == '+' && Another_Real_Num.sign == '-') {
      return true;
  }
  else if(this->sign == '-'&& Another_Real_Num.sign == '-'){
      BigReal comp1,comp2;
      comp1 = *this;
      comp2 = Another_Real_Num;
      //change the signs and compare if *this < Another_Real_Num
      comp1.sign = '+';
      comp2.sign = '+';
      return comp1<comp2;
  }
  else if(this->sign =='+' && Another_Real_Num.sign=='+') {
      if(this->integer[0]=='0') {
          for (int i = 0; i < this->integer.size(); i++) {
              if(this->integer[i]=='0')
                  this->integer.erase(this->integer.begin());
              else
                  break;
          }
      }
      if(Another_Real_Num.integer[0]=='0'){
          for (int i = 0; i < Another_Real_Num.integer.size(); i++) {
              if(Another_Real_Num.integer[i]=='0')
                  Another_Real_Num.integer.erase(Another_Real_Num.integer.begin());
              else
                  break;
          }
      }
      // compare the size of the integer part
      if (this->integer.size() > Another_Real_Num.integer.size()) {
          return true;
      } else if (this->integer.size() < Another_Real_Num.integer.size()) {
          return false;
      } else {
          // if this->integer.size() == Another_Real_Num.integer.size()
          for (int i = 0; i < this->integer.size(); ++i) {
              //compare the integer part by looping for each digit
              if (this->integer[i] - '0' > Another_Real_Num.integer[i] - '0') {
                  return true;
              } else if (this->integer[i] - '0' < Another_Real_Num.integer[i] - '0') {
                  return false;
              }
          }
          //compare the size of the fraction part
          if (this->fraction.size() > Another_Real_Num.fraction.size()) {
              // to make this->fraction.size() = Another_Real_Num.fraction.size()
              while (this->fraction.size() != Another_Real_Num.fraction.size()) {
                  Another_Real_Num.fraction += '0';
              }
          } else if (this->fraction.size() < Another_Real_Num.fraction.size()) {
              // to make this->fraction.size() = Another_Real_Num.fraction.size()
              while (this->fraction.size() != Another_Real_Num.fraction.size()) {
                  fraction += '0';
              }
          }
          for (int i = 0; i < this->fraction.size(); ++i) {
              //compare the fraction part by looping for each digit
              if (this->fraction[i] - '0' > Another_Real_Num.fraction[i] - '0') {
                  return true;
              } else if (this->fraction[i] - '0' < Another_Real_Num.fraction[i] - '0') {
                  return false;
              }
          }
      }
  }
      return false;
}
bool BigReal::operator<(BigReal Another_Real_Num) {
    // - is less than +
    if(this->sign == '-' && Another_Real_Num.sign == '+') {
        return true;
    }
    // + is not less than -
    else if(this->sign == '+' && Another_Real_Num.sign == '-') {
        return false;
    }

    else if(this->sign == '-'&& Another_Real_Num.sign == '-'){
        BigReal comp1,comp2;
        comp1 = *this;
        comp2 = Another_Real_Num;
        //change the signs and compare if *this > Another_Real_Num
        comp1.sign = '+';
        comp2.sign = '+';
        return comp1>comp2;
    }
    else if(this->sign =='+' && Another_Real_Num.sign=='+') {
        if(this->integer[0]=='0') {
            for (int i = 0; i < this->integer.size(); i++) {
                if(this->integer[i]=='0')
                    this->integer.erase(this->integer.begin());
                else
                    break;
            }
        }
        if(Another_Real_Num.integer[0]=='0'){
            for (int i = 0; i < Another_Real_Num.integer.size(); i++) {
                if(Another_Real_Num.integer[i]=='0')
                    Another_Real_Num.integer.erase(Another_Real_Num.integer.begin());
                else
                    break;
            }
        }
        // compare the size of the integer part
        if (this->integer.size() < Another_Real_Num.integer.size()) {
            return true;
        } else if (this->integer.size() > Another_Real_Num.integer.size()) {
            return false;
        } else {
            // if this->integer.size() == Another_Real_Num.integer.size()
            for (int i = 0; i < this->integer.size(); ++i) {
                // compare the integer part by looping for each digit
                if (this->integer[i] - '0' < Another_Real_Num.integer[i] - '0') {
                    return true;
                } else if (this->integer[i] - '0' > Another_Real_Num.integer[i] - '0') {
                    return false;
                }
            }
            // compare the size of the fraction part
            if (this->fraction.size() > Another_Real_Num.fraction.size()) {
                // to make this->fraction.size() = Another_Real_Num.fraction.size()
                while (this->fraction.size() != Another_Real_Num.fraction.size()) {
                    Another_Real_Num.fraction += '0';
                }
            } else if (this->fraction.size() < Another_Real_Num.fraction.size()) {
                //to make this->fraction.size() = Another_Real_Num.fraction.size()
                while (this->fraction.size() != Another_Real_Num.fraction.size()) {
                    this->fraction += '0';
                }
            }
            for (int i = 0; i < this->fraction.size(); ++i) {
                // compare the fraction part by looping for each digit
                if (this->fraction[i] - '0' < Another_Real_Num.fraction[i] - '0') {
                    return true;
                } else if (this->fraction[i] - '0' > Another_Real_Num.fraction[i] - '0') {
                    return false;
                }
            }
        }
    }
        return false;
}
bool BigReal::operator==(BigReal Another_Real_Num) {
    if(this->integer[0]=='0') {
        for (int i = 0; i < this->integer.size(); i++) {
            if(this->integer[i]=='0')
                this->integer.erase(this->integer.begin());
            else
                break;
        }
    }
    if(Another_Real_Num.integer[0]=='0'){
        for (int i = 0; i < Another_Real_Num.integer.size(); i++) {
            if(Another_Real_Num.integer[i]=='0')
                Another_Real_Num.integer.erase(Another_Real_Num.integer.begin());
            else
                break;
        }
    }
    if (this->fraction.back() == '0') {
        for (int i = 0; i < this->fraction.size(); ++i) {
            if (this->fraction.back() == '0')
                this->fraction.pop_back();
            else
                break;
        }
    }

    if (Another_Real_Num.fraction.back() == '0') {
        for (int i = 0; i < Another_Real_Num.fraction.size(); ++i) {
            if (Another_Real_Num.fraction.back() == '0')
                Another_Real_Num.fraction.pop_back();
            else
                break;
        }
    }
    bool equal;
    // compare the signs
    if (this->sign != Another_Real_Num.sign)
        equal = false;
    else {
        // compare the integer part
        if (this->integer == Another_Real_Num.integer) {
            // compare the fraction part
            if (this->fraction != Another_Real_Num.fraction) {
                equal = false;
            } else
                equal = true;
        } else
            equal = false;
    }
    return equal;
}
BigReal BigReal::operator+(BigReal &Another_Real_Num) {
    BigReal result;
    // check if the two signs are the same
    if (this->sign == Another_Real_Num.sign){
        if(this->integer.size()>Another_Real_Num.integer.size()){
            // to make this->integer.size() = Another_Real_Num.integer.size()
            while(this->integer.size()!=Another_Real_Num.integer.size()){
                Another_Real_Num.integer = '0' + Another_Real_Num.integer;
            }
        }
        else if(this->integer.size()<Another_Real_Num.integer.size()){
            // to make this->integer.size() = Another_Real_Num.integer.size()
            while(this->integer.size()!=Another_Real_Num.integer.size()){
                this->integer = '0' + this->integer;
            }
        }
        if(this->fraction.size()>Another_Real_Num.fraction.size()){
            // to make this->fraction.size() = Another_Real_Num.fraction.size()
            while(this->fraction.size()!=Another_Real_Num.fraction.size()){
                Another_Real_Num.integer += '0';
            }
        }
        else if(this->fraction.size()<Another_Real_Num.fraction.size()){
            // to make this->fraction.size() = Another_Real_Num.fraction.size()
            while(this->fraction.size()!=Another_Real_Num.fraction.size()){
                this->fraction += '0';
            }
        }
        int carry =0, result_integer,result_fraction;
        for (int i = this->fraction.size()-1; i >= 0; --i) {
            // add the fraction parts
            result_fraction = this->fraction[i]-'0'+(Another_Real_Num.fraction[i]-'0')+carry;
            if(i==this->fraction.size()-1) {
                result.fraction = to_string(result_fraction % 10);
            }
            else{
                result.fraction = to_string(result_fraction%10)+result.fraction;
            }
            carry=result_fraction/10;
        }
        for (int i = this->integer.size()-1; i >=0; --i) {
            // add the integer parts
            result_integer = this->integer[i]-'0'+(Another_Real_Num.integer[i]-'0')+carry;
            if(i==this->integer.size()-1){
                result.integer = to_string(result_integer%10);
            }
            else
                result.integer = to_string((result_integer%10))+result.integer;
            carry = result_integer/10;
        }
        if(carry>0)
            result.integer = to_string(carry) + result.integer;
        result.sign = this->sign;
        }
    else if(this->sign=='+'&&Another_Real_Num.sign=='-'){
        // (+) + (-) == (+) - (+)
        Another_Real_Num.sign = '+';
        return *this-Another_Real_Num;
    }
    else if(this->sign=='-'&&Another_Real_Num.sign=='+'){
        // (-) + (+) == (+) - (+)
        this->sign = '+';
        return Another_Real_Num-*this;
    }
    return result;
}
BigReal BigReal::operator -(BigReal &Another_Real_Num) {
    BigReal result;
    if(this->integer.size()>Another_Real_Num.integer.size()){
        // to make this->integer.size() = Another_Real_Num.integer.size()
        while (this->integer.size()!=Another_Real_Num.integer.size()) {
            Another_Real_Num.integer='0'+Another_Real_Num.integer;
        }
    }
    else if(this->integer.size()<Another_Real_Num.integer.size()){
        // to make this->integer.size() = Another_Real_Num.integer.size()
        while(this->integer.size()!=Another_Real_Num.integer.size())
            this->integer='0'+this->integer;
    }
    if(this->fraction.size()>Another_Real_Num.fraction.size()){
        // to make this->fraction.size() = Another_Real_Num.fraction.size()
        while(this->fraction.size()!=Another_Real_Num.fraction.size()){
            Another_Real_Num.fraction += '0';
        }
    }
    else if(this->fraction.size()<Another_Real_Num.fraction.size()){
        // to make this->fraction.size() = Another_Real_Num.fraction.size()
        while(this->fraction.size()!=Another_Real_Num.fraction.size()){
            this->fraction += '0';
        }
    }
    int borrow = 0,result_integer,result_fraction;
    // check if the two signs are the same
    if(this->sign == '+' && Another_Real_Num.sign == '+'){
        // check which one is greater
        if(*this<Another_Real_Num){
            result.sign = '-';
            swap(*this,Another_Real_Num);
        }
        for (int i = this->fraction.size()-1; i >=0 ; --i) {
            // subtract the fraction parts
            result_fraction = this->fraction[i]-'0'- (Another_Real_Num.fraction[i]-'0')+borrow;
            if(result_fraction<0){
                result_fraction+=10;
                borrow = 1;
            }
            else
                borrow = 0;
            if(i == fraction.size()-1)
                result.fraction = to_string(result_fraction);
            else
                result.fraction = to_string(result_fraction)+result.fraction;
        }
        for(int i = integer.size()-1;i>=0;i--){
            // subtract the integer parts
            result_integer = this->integer[i]-'0'-(Another_Real_Num.integer[i]-'0')+borrow;
            if(result_integer<0){
                result_integer+=10;
                borrow = 1;
            }
            else
                borrow = 0;
            if(i == integer.size()-1)
                result.integer = to_string(result_integer);
            else
                result.integer = to_string(result_integer)+result.integer;
        }
    }
    else if(sign == '-' && Another_Real_Num.sign == '-'){
        BigReal answer;
        this->sign = '+';
        Another_Real_Num.sign='+';
        answer= *this-Another_Real_Num;
        if(*this>Another_Real_Num)
            answer.sign='-';
        else if(*this<Another_Real_Num)
            answer.sign = '+';
        return answer;
    }
    else if(this->sign=='+' && Another_Real_Num.sign == '-'){
        // (+) - (-) == (+) + (+)
        Another_Real_Num.sign = '+';
        return *this+Another_Real_Num;
    }
    else if(this->sign == '-' && Another_Real_Num.sign == '+'){
        // (-) - (+) == (-) + (-)
        Another_Real_Num.sign='-';
        return *this+Another_Real_Num;
    }
    return result;
}
void BigReal ::print() {
    cout << sign << integer << '.' << fraction << "\n";
}
istream& operator >> (istream& in, BigReal& num) {
    string input;
    in >> input;
    num = BigReal(input);
    return in;
}
ostream& operator << (ostream& out, BigReal& num) {
    out << num.sign << num.integer << '.' << num.fraction ;
    return out;
}
