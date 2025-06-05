#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string brand;
    int year;
    Vehicle(string brand, int year) : brand(brand), year(year) {}
    void showDetails() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {
public:
    int numDoors;
    Car(string brand, int year, int numDoors)
        : Vehicle(brand, year), numDoors(numDoors) {}
    void showCar() {
        showDetails();
        cout << "Doors: " << numDoors << endl;
    }
};

class Bike : public Vehicle {
public:
    bool hasCarrier;
    Bike(string brand, int year, bool hasCarrier)
        : Vehicle(brand, year), hasCarrier(hasCarrier) {}
    void showBike() {
        showDetails();
        cout << "Has Carrier: " << (hasCarrier ? "Yes" : "No") << endl;
    }
};

int main() {
    Car c("Toyota", 2022, 4);
    Bike b("Yamaha", 2021, true);
    c.showCar();
    b.showBike();
    return 0;
}
