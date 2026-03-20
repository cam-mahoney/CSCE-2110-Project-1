#ifndef NODE_H
#define NODE_H

#pragma once

#include "Driver.h"

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class LinkedList;

class Node {
    private:
        Driver* data;
        Node* next;

    public:
        Node(Driver* driver);

        friend class LinkedList;
};

#endif