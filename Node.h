#ifndef NODE_H
#define NODE_H

//#pragma once // header guard, prevents multiple inclu from this header

#include "Driver.h" // for when driver is implemented

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class LinkedList; // forward dec for LL

class Node {
    private:
        Driver* data;
        Node* next;

    public:
        Node(Driver* driver);

        friend class LinkedList; // LL gets access to priv mem
        friend class DriverDatabase; 
};

#endif
