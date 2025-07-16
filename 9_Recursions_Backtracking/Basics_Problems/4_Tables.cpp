#include <iostream>
using namespace std;

void printTable(int n, int i = 1) {
    if (i > 10) return; // Base case: stop after 10
    cout << n << " x " << i << " = " << n * i << endl;
    printTable(n, i + 1); // Recursive call with incremented i
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Multiplication Table of " << n << ":\n";
    printTable(n);
}