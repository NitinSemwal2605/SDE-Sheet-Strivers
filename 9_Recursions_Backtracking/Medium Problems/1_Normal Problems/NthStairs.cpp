#include <iostream>
using namespace std;

int NthStairs(int n) {
    if (n < 0) return 0; // No way to climb negative stairs
    if (n == 0 || n == 1) return 1; // One way to climb 0 or 1 stair
    return NthStairs(n - 1) + NthStairs(n - 2); // Sum of ways to climb n-1 and n-2 stairs
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    cout << "Number of ways to climb " << n << " stairs is: " << NthStairs(n) << endl;
    return 0;
}