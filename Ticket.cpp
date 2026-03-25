#include "Ticket.h"
#include <iostream>

using namespace std;

Ticket::Ticket() {}

Ticket::Ticket(Date d, string loc)
    : date(d), location(loc) {}

Date Ticket::getDate() const {
    return date;
}

string Ticket::getLocation() const {
    return location;
}

void Ticket::display() const {
    cout << "Ticket at " << location << " on ";
    date.display();
    cout << endl;
}