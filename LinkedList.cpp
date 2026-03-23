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
        delete temp->data;
        delete temp;
    }
}

void LinkedList::insertBeginning(Driver* driver) {
    Node* newNode = new Node(driver);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insert(Driver* driver) {
    Node* newNode = new Node(driver);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

Driver* LinkedList::search(int id) const {
    Node* current = head;

    while (current != nullptr) {
        if (current->data->getId() == id) {
            return current->data;
        }
        current = current->next;
    }

    return nullptr;
}

void LinkedList::remove(int id) {
    if (head == nullptr) return;

    if (head->data->getId() == id) {
        Node* temp = head;
        head = head->next;

        delete temp->data;
        delete temp;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        if (current->next->data->getId() == id) {
            Node* temp = current->next;
            current->next = temp->next;

            delete temp->data;
            delete temp;
            return;
        }
        current = current->next;
    }
}

