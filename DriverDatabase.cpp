#include "DriverDatabase.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

DriverDatabase::DriverDatabase(int size): drivers(size) {}

DriverDatabase::~DriverDatabase() {
    Node* current = dateList.getHead();
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current->data; 

        current = nextNode;
    }

    current = inactiveDrivers.getHead();
    while (current != nullptr) {
        Node* nextNode = current->next;

        delete current->data;

        current = nextNode;
    }
}


void DriverDatabase::insertDriver(Driver* d) {
    drivers.insert(d);
    countyList.insertByCounty(d);
    dateList.insertByDate(d);
}

// create driver
Driver* DriverDatabase::createDriver() {
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

    return new Driver(id, name, exp, work, medical, addr, dob, lic);
}

//load
void DriverDatabase::loadFromFile() {
    ifstream file("Drivers.tsv");

    if (!file.is_open()) {
        cout << "File error\n";
        return;
    }
    
    string dummy;
    getline(file, dummy); // skips the first line of random titles
    
    while (true) {
        int id, exp;
        string name, work, medical, county;
        int d, m, y;
        int ld, lm, ly;
        string hasTicket;
        string tl, td, tm, ty;

        file >> id >> name >> exp >> work >> medical >> county
             >> d >> m >> y
             >> ld >> lm >> ly
             >> hasTicket;
        file >> hasTicket;

        if (hasTicket == "Y") {
            file >> tl >> td >> tm >> ty;
        } else {
        }


        if (file.fail()) break;

        Date dob(y, m, d);
        Date license(ld, lm, ly);
        Address addr("", "", county, "", "");

        Driver* driver = new Driver(id, name, exp, work, medical, addr, dob, license);

        if (hasTicket == "Y") {
            int td, tm, ty;
            string location;

            file >> td >> tm >> ty >> location;

            driver->addTicket(Date(ty, tm, td), location);
        }

        insertDriver(driver);
    }

    file.close();
}


//search
Driver* DriverDatabase::searchDriver(int id){
    return drivers.search(id);
}

//remove
void DriverDatabase::removeDriver(int id, bool isMigrating) {
    Driver* target = drivers.search(id);

    if (target != nullptr) {
        if (isMigrating) {
            moveToInactive(target);
        }
        drivers.remove(id);
        countyList.removeNode(target);
        dateList.removeNode(target);
    }
}

//movetoinactive
void DriverDatabase::moveToInactive(Driver* d) {
    inactiveDrivers.insertByCounty(d);
}

//retrieveNewest
void DriverDatabase::retrieveNewest(int N) {
    int size = 0;
    Node* current = dateList.getHead();

    // count size
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    int skip = size - N;
    if (skip < 0) skip = 0;

    current = dateList.getHead();

    for (int i = 0; i < skip; i++) {
        current = current->next;
    }

    while (current != nullptr) {
        current->data->display();
        current = current->next;
    }
}

//retrieveOldest
void DriverDatabase::retrieveOldest(int N) {
    Node* current = dateList.getHead();

    int count = 0;
    while (current != nullptr && count < N) {
        current->data->display();
        current = current->next;
        count++;
    }
}

void DriverDatabase::mainFlow() {
    loadFromFile();

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            Driver* newD = createDriver();
            insertDriver(newD);
        }
        else if (choice == 2) {
            int id;
            cin >> id;
            Driver* d = searchDriver(id);
            if (d) d->display();
        }
        else if (choice == 3) {
            int N;
            cin >> N;
            retrieveNewest(N);
        }
        else if (choice == 4) {
            int N;
            cin >> N;
            retrieveOldest(N);
        }
        else if (choice == 5) {
            int id;
            cin >> id;
            removeDriver(id, true);
        }
    }
}
