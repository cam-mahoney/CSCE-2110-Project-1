#include "Driver.h"
#include <iostream>

using namespace std;

Driver::Driver() {}
    
Driver::Driver(int id, string name, int exp, string work, string medical, Address addr, Date dob, Date license) : id(id), name(name), experienceYears(exp), workCategory(work), medicalCondition(medical), address(addr), dateOfBirth(dob), licenseDate(license) {}
    
Driver:: ~Driver() {}
    
int Driver::getID() const { //returns the id of the driver
    return id; 
}
int Driver::getExperience() const { //returns how many years of experience the driver has
    return experienceYears; 
}
Date Driver::getLicenseDate() const { //returns the date the driver got their license
    return licenseDate; 
}
string Driver::getCounty() const { //returns the county the driver is in
    return address.county; 
}
    
void Driver::addTicket(Date d, string loc) { // adds a ticket to the driver
    ticket.addTicket(d, loc);
}
    
void Driver::display() const { // displays the driver's information
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

