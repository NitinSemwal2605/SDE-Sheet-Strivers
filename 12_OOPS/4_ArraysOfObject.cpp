#include <bits/stdc++.h>
using namespace std;

class Employee {
    char name[20];
    float age;
    public:
    void getData(void);
    void putData(void);
};

void Employee::getData(void) {
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void Employee::putData(void) {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

int main() {
    const int SIZE = 3;
    Employee emp[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter details for employee " << (i + 1) << ":" << endl;
        emp[i].getData();
    }

    cout << "\nEmployee Details:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Employee " << (i + 1) << ":" << endl;
        emp[i].putData();
    }

    return 0;
}


/*
    Conclusion:
    1. Arrays of objects can be created to manage multiple instances of a class.
    2. Each object in the array can have its own state and behavior.
    3. Array indexing is used to access individual objects.
    4. Memory for the objects is allocated on the stack (for automatic arrays) or the heap (for dynamic arrays).
    5. Objects in an array can be manipulated using loops for efficient processing.
*/