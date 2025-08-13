#include <bits/stdc++.h>
using namespace std;

// Parent class
class Vehicle {
public:
    virtual void start() {
        cout << "Starting a generic vehicle" << endl;
    }

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void start() override {
        cout << "Starting a car" << endl;
    }
};

class Bike : public Vehicle {
public:
    void start() override {
        cout << "Starting a bike" << endl;
    }
};

class Truck : public Vehicle {
public:
    void start() override {
        cout << "Starting a truck" << endl;
    }
};

int main() {
    Vehicle* v1 = new Car();
    Vehicle* v2 = new Bike();
    Vehicle* v3 = new Truck();

    v1->start(); // Starting a car
    v2->start(); // Starting a bike
    v3->start(); // Starting a truck

    delete v1;
    delete v2;
    delete v3;

    return 0;
}
