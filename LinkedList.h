#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class Driver;
class Node;


class LinkedList {
private:
    Node* head;
    
public:
    LinkedList();
    ~LinkedList();

    void insertBeginning(Driver* driver);
    void insert(Driver* driver);
    Driver* search(int id) const;
    void remove(int id);
};


#endif

