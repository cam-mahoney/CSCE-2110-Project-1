#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>

using namespace std;

class Address {
public:
    string street;
    string city;
    string county;
    string state;
    string zipcode;

    Address() {}

    Address(string st, string c, string co, string s, string z): street(st), city(c), county(co), state(s), zipcode(z) {}

    void display() const { //outputs the address
        cout << street << ", " << city << ", " << county << ", " << state << " " << zipcode;
    }
};

#endif