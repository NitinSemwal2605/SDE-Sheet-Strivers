#include <bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    void start() {
        cout << "Vehicle started" << endl;
    }

    void start(int speed) {
        cout << "Vehicle started at speed: " << speed << " km/h" << endl;
    }

    void start(string type) {
        cout << "Vehicle started, type: " << type << endl;
    }
};

int main() {
    Vehicle v;
    v.start();
    v.start(60);
    v.start("Car");
    return 0;
}

/*
Compile-time polymorphism is achieved through function overloading and operator overloading.
Means We've same function name with different parameters.
In this example, we have multiple start() methods in the Vehicle class, demonstrating function overloading.
*/