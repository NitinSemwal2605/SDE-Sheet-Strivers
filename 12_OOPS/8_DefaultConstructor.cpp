#include <bits/stdc++.h>
using namespace std;

class Sample {
    int a;
    int b;

public:
    Sample() { // Setting default values
        a = 0;
        b = 0;
    }

    void display() {
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {
    Sample s1;
    s1.display();

    return 0;
}