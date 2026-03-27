#include "Driver.h"
#include <iostream>

using namespace std;

Driver::Driver() {
    id = 0;
    experienceYears = 0;
    ticketCount = 0;
    ticketCapacity = 2;
    tickets = new Ticket[ticketCapacity]; // Allocate memory
}

Driver::Driver(int id, string name, int exp, string work, string medical, Address addr, Date dob, Date license) 
    : id(id), name(name), experienceYears(exp), workCategory(work), 
      medicalCondition(medical), address(addr), dateOfBirth(dob), licenseDate(license) 
{
    ticketCount = 0;
    ticketCapacity = 2;
    tickets = new Ticket[ticketCapacity]; // Allocate memory here
}
Driver:: ~Driver() {
    delete[] tickets;
}

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
string Driver::getAgeCategory() const {
    int currentYear = 2026;
    int age = currentYear - dateOfBirth.getYear();

    if (age <= 28) return "Youth";
    if (age <= 50) return "Middle-aged";
    return "Senior";
}

string Driver::getExperienceCategory() const {
    if (experienceYears <= 5) return "New";
    if (experienceYears <= 15) return "Moderate";
    return "Highly Experienced";
}

string Driver::getMedicalCategory() const {
    return medicalCondition;
}

string Driver::getWorkCategory() const {
    return workCategory;
}

void Driver::addTicket(Date d, string loc) { // adds a ticket to the driver
    if (ticketCount == ticketCapacity) {
        ticketCapacity *= 2;

        Ticket* newArr = new Ticket[ticketCapacity];

        for (int i = 0; i < ticketCount; i++) {
            newArr[i] = tickets[i];
        }


        delete[] tickets;
        tickets = newArr;
    }
    tickets[ticketCount++] = Ticket(d, loc);
}


void Driver::display() const { // displays the driver's information
    cout << "ID: " << id << "\nName: " << name << endl;
    cout << "Experience: " << experienceYears << " years\n";
    cout << "Work: " << workCategory << "\nMedical: " << medicalCondition << endl;

    cout << "Date of Birth: ";
    dateOfBirth.display();
    cout << endl;

    cout << "License Date: ";
    licenseDate.display();
    cout << endl;

    cout << "Address: ";
    address.display();
    cout << endl;

    if (ticketCount > 0) {
        cout << "Tickets: " << endl;
        for (int i = 0; i < ticketCount; i++){
            tickets[i].display();
            cout << endl;
        }
    } 
    else {
        cout << "No tickets\n";
    }
}
