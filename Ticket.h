#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Date.h"

using namespace std;

class Ticket {
private:
    Date date;
    string location;

public:
    Ticket();

    Date getDate() const; //returns the date of the ticket

    string getLocation() const;

    void display() const;
};

#endif