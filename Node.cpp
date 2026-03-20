#include "Node.h" // Needs Driver class to work

Node::Node(Driver* driver){ // constructor
    data = driver;
    next = nullptr;
}