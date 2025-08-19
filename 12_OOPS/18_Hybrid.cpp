#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle starting...\n";
    }
};

class FourWheeler : public Vehicle {
public:
    void fourWheelDrive() {
        cout << "Four wheel drive on\n";
    }
};

class OffRoad {
public:
    void offRoadMode() {
        cout << "Off-road mode enabled\n";
    }
};

class SUV : public FourWheeler, public OffRoad {
public:
    void suvFeatures() {
        cout << "SUV features activated\n";
    }
};

int main() {
    SUV mySUV;
    mySUV.start();          // from Vehicle (multilevel inheritance)
    mySUV.fourWheelDrive(); // from FourWheeler
    mySUV.offRoadMode();    // from OffRoad (multiple inheritance)
    mySUV.suvFeatures();
    return 0;
}
