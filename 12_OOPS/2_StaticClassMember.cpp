#include <bits/stdc++.h>
using namespace std;

class item{
    static int count;
    int number;
public:
    void getdata(int a) {
        number = a;
        count++;
    }
    void showdata() {
        cout << "Count: ";
        cout << count << endl;
    }
};

int item::count = 0; // Definition of static member variable

int main() {
    item obj1, obj2, obj3;
    
    obj1.getdata(1);
    obj1.showdata(); // Count: 1
    
    obj2.getdata(2);
    obj2.showdata(); // Count: 2
    
    obj3.getdata(3);
    obj3.showdata(); // Count: 3

    return 0;
}

/*
Static Member Variables :
    1. Shared among all objects of the class.
    2. Can be accessed using the class name.
    3. Initialized only once.
*/