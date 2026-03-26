#include "DriverDatabase.h"
#include "Driver.h"
#include "Address.h"
#include "Date.h"
#include <iostream>
#include <limits>

using namespace std;

enum menu_option { // enum for menu options, easier to read and watnot
    EXIT = 0,
    ADD_DRIVER = 1,
    SEAERCH = 2,
    NEWEST = 3,
    OLDEST = 4,
    REMOVE = 5,
    ADD_TICKET = 6
};

int main() {
    DriverDatabase db(100);

    db.loadFromFile();

    int input;
    menu_option choice; // store men choiec as enum

    do {
        cout << "\nMenu:\n"
             << "1. Add Driver\n"
             << "2. Search Driver\n"
             << "3. Retrieve Newest Drivers\n"
             << "4. Retrieve Oldest Drivers\n"
             << "5. Remove Driver\n"
             << "6. Add Ticket to Driver\n"
             << "0. Exit\n"
             << "Choose an option: ";

        //int choice;
        //cin >> choice; 

        cin >> input;
        choice = static_cast<menu_option>(input); // cast input to enum, for reading switch cases

        switch (choice) {
            case ADD_DRIVER: { // moved to have all input collection in main, the original code is commented out in DriverDatabase .cpp and .h
                int id, exp;
                string name, work, medical, st, city, co, state, zip;
                int d, m, y, ld, lm, ly;

                cout << "Enter ID, Name, Experience: ";
                cin >> id >> name >> exp;
                cout << "Work Category, Medical: ";
                cin >> work >> medical;
                cout << "Address (Street, City, County, State, Zip): ";
                cin >> st >> city >> co >> state >> zip;
                cout << "DOB (D M Y): ";
                cin >> d >> m >> y;
                cout << "License Date (D M Y): ";
                cin >> ld >> lm >> ly;

                Address addr(st, city, co, state, zip);
                Date dob(d, m, y);
                Date lic(ld, lm, ly);

                Driver* newDriver = new Driver(id, name, exp, work, medical, addr, dob, lic);
                db.insertDriver(newDriver);

                break;
            }
            case SEAERCH: {
                // needs search implementation
                break;
            }
            case NEWEST: {
                // needs newest implementation
                break;
            }
            case OLDEST: {
                // needs oldest implementation
                break;
            }
            case REMOVE: {
                // needs a removal implementation
                break;
            }
            case ADD_TICKET: {
                // needs adding a ticket implementation
                break;
            }
            case EXIT:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != EXIT);

    return 0;
}