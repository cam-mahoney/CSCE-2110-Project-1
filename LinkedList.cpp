#include "LinkedList.h"
#include "Node.h"
#include "Driver.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;

        // delete stored Driver
        delete temp;
    }
}

void LinkedList::insertByCounty(Driver* driver) {
    Node* newNode = new Node(driver);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    // insert at beginning
    if (driver->getCounty() < head->data->getCounty()) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr &&
           current->next->data->getCounty() < driver->getCounty()) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    // update tail if inserted at end
    if (newNode->next == nullptr) {
        tail = newNode;
    }
}

void LinkedList::insertByDate(Driver* driver) {
    Node* newNode = new Node(driver);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    // insert at beginning (oldest)
    if (driver->getIssueDate() < head->data->getIssueDate()) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr &&
           current->next->data->getIssueDate() < driver->getIssueDate()) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    // update tail if inserted at end
    if (newNode->next == nullptr) {
        tail = newNode;
    }
}


void LinkedList::removeNode(Driver* driver) {
    if (head == nullptr) return;

    if (head->data == driver) {
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->data == driver)  {
            Node* temp = current->next;
            current->next = temp->next;

            if (temp == tail) {
                tail = current;
            }

            delete temp;
            return;
        }
        current = current->next;
    }
}

Driver* LinkedList::searchByID(int id) { // added later
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data->getID() == id)
            return temp->data;

        temp = temp->next;
    }

    return nullptr;
}
