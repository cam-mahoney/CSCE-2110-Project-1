#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Driver;
class Node;


class LinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    LinkedList();
    ~LinkedList();

    void insertByCounty(Driver* driver);
    void insertBYDate(Driver* driver);
    Driver* searchByID(int id); // added later

    void removeNode(Driver* driver);

    Node* getHead() const;
    Node* getTail() const;
};


#endif

