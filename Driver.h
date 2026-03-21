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
    
        Ticket ticket;
    
    public:
        Driver() {}
    
        Driver(int id, string name, int exp, string work, string medical, Address addr, Date dob, Date license) : id(id), name(name), experienceYears(exp), workCategory(work), medicalCondition(medical), address(addr), dateOfBirth(dob), licenseDate(license) {}
    
        virtual ~Driver() {}
    
        int getID() const { //returns the id of the driver
            return id; 
        }
        int getExperience() const { //returns how many years of experience the driver has
            return experienceYears; 
        }
        Date getLicenseDate() const { //returns the date the driver got their license
            return licenseDate; 
        }
        string getCounty() const { //returns the county the driver is in
            return address.county; 
        }
    
        void addTicket(Date d, string loc) { // adds a ticket to the driver
            ticket.addTicket(d, loc);
        }
    
        virtual void display() const { // displays the driver's information
            cout << "ID: " << id << "\nName: " << name << endl;
            cout << "Experience: " << experienceYears << " years\n";
            cout << "Work: " << workCategory << "\nMedical: " << medicalCondition << endl;
    
            cout << "License Date: ";
            licenseDate.display();
            cout << endl;
    
            cout << "Address: ";
            address.display();
            cout << endl;
    
            if (ticket.exists()) {
                cout << "Ticket at " << ticket.getLocation() << " on ";
                ticket.getDate().display();
                cout << endl;
            } 
            else {
                cout << "No tickets\n";
            }
        }
};

#endif