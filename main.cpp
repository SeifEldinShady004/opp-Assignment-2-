// File:  A2_S5_20220127_Problem2.cpp
// Purpose:  the program converts male speech to inclusive speech that includes both male and female
// Author: Rahma Maged Mohamed Mohamed
// Section: S5
// ID: 20220127
// TA: Maya Ahmed
// Date: 5 Nov 2023
#include <iostream>
#include <string>
using namespace std;
int main() {
    cout<<"Enter a sentence \n";
    string str;
    getline(cin,str);
    string s[str.size()];
    for (int i=0;i<str.size();i++) {
       s[i]=str[i];
    }
    for (int i=0;i<str.size();i++) {
        // if "he" exists , convert it to "he or she"
        if (s[i]+s[i+1]=="he") {
            s[i] = "he or ";
            s[i+1]="she";
        }
        // if "He" exists , convert it to "He or she"
        else if (s[i] + s[i + 1] == "He") {
            s[i] = "He or ";
            s[i+1]="she";
        }
        // if "his" exists , convert it to "his or her"
        else if (s[i] + s[i + 1] + s[i + 2] == "his"){
            s[i] = "his ";
            s[i+1]="or ";
            s[i+2]="her";
        }
        // if "His" exists , convert it to "His or her"
        else if (s[i] + s[i + 1] + s[i + 2] == "His") {
            s[i] = "His ";
            s[i+1]="or ";
            s[i+2]="her";
        }
        // if "him" exists , convert it to "him or her"
        else if (s[i] + s[i + 1] + s[i + 2] == "him") {
            s[i] = "him ";
            s[i+1]="or ";
            s[i+2]="her";
        }
        // if "Him" exists , convert it to "Him or her"
        else if (s[i] + s[i + 1] + s[i + 2] == "Him") {
            s[i] = "Him ";
            s[i+1]="or ";
            s[i+2]="her";
        }
    }
    for(int i=0;i<str.size();i++)
        cout<<s[i];
}
