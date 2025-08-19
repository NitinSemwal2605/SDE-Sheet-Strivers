#include <iostream>
using namespace std;

class Printer {
public:
    void print() {
        cout << "Printing document\n";
    }
};

class Scanner {
public:
    void scan() {
        cout << "Scanning document\n";
    }
};

class AllInOne : public Printer, public Scanner {
    // inherits both print() and scan()
};

int main() {
    AllInOne device;
    device.print();
    device.scan();
    return 0;
}
