#include <bits/stdc++.h>
using namespace std;

class B; // Forward declaration of class B

class A {
    int x;
public:
    A(int val) : x(val) {}
    // Friend function declaration
    friend void showSum(A, B);
};

class B {
    int y;
public:
    B(int val) : y(val) {}
    // Friend function declaration
    friend void showSum(A, B);
};

void showSum(A a, B b) {
    cout << "Sum: " << (a.x + b.y) << endl;
}

int main() {
    A a(10);
    B b(20);
    showSum(a, b);
    return 0;
}

