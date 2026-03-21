#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Date.h"

using namespace std;

class Ticket {
private:
    bool hasTicket;
    Date date;
    string location;

public:
    Ticket() : hasTicket(false) {}

    void addTicket(Date d, string loc) { //adds a ticket
        hasTicket = true;
        date = d;
        location = loc;
    }

    bool exists() const { //returns true if the driver has a ticket
        return hasTicket;
    }

    Date getDate() const { //returns the date of the ticket
        return date;
    }

    std::string getLocation() const { //returns the location of the ticket
        return location;
    }
};

#endif