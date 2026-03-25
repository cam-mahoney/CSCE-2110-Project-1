#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <iostream>
#include "Address.h"
#include "Date.h"
#include "Ticket.h"

using namespace std;

class Driver {
    protected:
        int id;
        string name;

        int experienceYears;
    
        string workCategory;
        string medicalCondition;
    
        Address address;
        Date dateOfBirth;
        Date licenseDate;

        Ticket* tickets;
        int ticketCount;
        int ticketCapacity;

    public:
        Driver(int id, string name, int exp, string work, string medical, Address addr, Date dob, Date license);

        void addTicket(Date d, string loc);

        Driver(const Driver& other);
        Driver& operator=(const Driver& other);
        ~Driver();

        int getID() const;
        string getCounty() const;
        void display() const;
};

#endif