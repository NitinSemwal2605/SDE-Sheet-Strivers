#include <bits/stdc++.h>
using namespace std;

class Test{
    int code;
    static int count; // Static member variable to keep track of the count

public:
    void setCode(void){
        code = ++count;
    }
    void showCode(void){
        cout << "Code: " << code << endl;
    }

    static void showCount(void){ // Static member function
        cout << "Count: " << count << endl;
    }
};

int Test::count = 0; // Initialize static member variable

int main(){
    Test t1, t2, t3; // Now we have 3 objects of Test

    t1.setCode();
    t2.setCode();
    t3.setCode();

    t1.showCode();
    t2.showCode();
    t3.showCode();

    Test::showCount(); // Static member function called using class name

    return 0;
}