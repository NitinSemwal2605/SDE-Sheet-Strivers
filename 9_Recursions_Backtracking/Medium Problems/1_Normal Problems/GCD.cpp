#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main(){
    int a ,b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    GCD(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << GCD(a, b) << endl;
    return 0;
}