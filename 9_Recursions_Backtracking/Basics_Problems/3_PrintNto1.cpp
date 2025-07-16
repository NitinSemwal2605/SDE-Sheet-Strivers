#include <iostream>
using namespace std;

void solve(int n) {
    if (n < 1) return; // Base case: if n is less than 1, return
    cout << n << " "; // Print the current value of n
    solve(n - 1); // Recursive call with n-1
}

int main (){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    cout << "Printing from " << n << " to 1:" << endl;
    solve(n);
    return 0;
}