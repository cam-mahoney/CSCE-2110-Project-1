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

        cin >> input;
        choice = static_cast<menu_option>(input); // cast input to enum, for reading switch cases

        switch (choice) {
            case ADD_DRIVER: { // adds a new driver to database, prompts user for all info
                int id, exp;
                string name, work, medical, st, city, co, state, zip;
                int d, m, y, ld, lm, ly;

                cout << "Enter ID: ", cin >> id;

                cout << "Enter Name (FIRST_LAST): ", cin >> name;

                cout << "Enter Experience Years: ", cin >> exp;

                cout << "Work Category: ", cin >> work;

                cout << "Enter Medical Information: ", cin >> medical;

                cout << "\n------- Address -------\n";
                cout << "Enter Street Name: ", cin >> st;
                cout << "Enter City Name: ", cin >> city;
                cout << "Enter County Name: ", cin >> co;
                cout << "Enter State: ", cin >> state;
                cout << "Enter Zip: ", cin >> zip;

                cout << " \n------- Date of Birth -------\n";
                cout << "Enter Day: ", cin >> d;
                cout << "Enter Month: ", cin >> m;
                cout << "Enter Year: ", cin >> y;

                cout << " \n------- License Date -------\n";
                cout << "Enter Day: ", cin >> ld;
                cout << "Enter Month: ", cin >> lm;
                cout << "Enter Year: ", cin >> ly;

                Address addr(st, city, co, state, zip);
                Date dob(d, m, y);
                Date lic(ld, lm, ly);

                Driver* newDriver = new Driver(id, name, exp, work, medical, addr, dob, lic);
                db.insertDriver(newDriver);

                break;
            }
            case SEAERCH: { // searches for a driver by ID and displays all info if they are found
                int id;
                cout << "Enter Driver ID: ";
                cin >> id;

                Driver* found = db.searchDriver(id);

                if (found != nullptr){
                    found->display();
                }else{
                    cout << "Driver not found.\n";
                }
                break;
            }
            case NEWEST: { // retrieves and displays the N newest drivers based on license date
                int N;
                cout << "Enter number of newest drivers: ";
                cin >> N;

                db.retrieveNewest(N);
                break;
            }
            case OLDEST: { // retrieves and displays the N oldest driver based on license date
                int N;
                cout << "Enter number of oldest drivers: ";
                cin >> N;

                db. retrieveOldest(N);
                
                break;
            }
            case REMOVE: { // removes a driver by ID, moves them to an inactive list within the database
                int id;
                cout << "Enter Driver ID to remove: ";
                cin >> id;

                db.removeDriver(id,true); // true = move to inactive

                cout << "Driver removed (if found).\n";
                break;
            }
            case ADD_TICKET: { // adds a tickt to a driver by ID, then prompts the user for the date and location of the ticket, adds it to the driver's record
                int id;
                cout << "Enter Driver ID: ";
                cin >> id;

                Driver* d_ptr = db.searchDriver(id); 
                if(d_ptr != nullptr) {
                    int d, m, y;
                    string loc;
                    cout << "Enter Date of ticket (D M Y): ";
                    cin >> d >> m >> y;
                    cout << "Enter Location:";
                    cin >> loc;

                    d_ptr->addTicket(Date(d,m,y), loc);

                    cout << "Ticket added.\n";
                }else{
                    cout << "Driver not found.\n";
                }
                break;
            }
            case EXIT: // exits program
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != EXIT);

    return 0;
}
