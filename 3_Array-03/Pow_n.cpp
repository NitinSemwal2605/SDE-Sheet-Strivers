#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans = 1.0;
    for (int i = 0; i < n; i++) {
      ans = ans * x;
    }
    return ans;
}

int main() {
    double x = 2.00000;
    int n = 10;
    cout << myPow(x, n) << endl;
    return 0;
}

/*
Approach:
1. The problem is to calculate x raised to the power n (x^n).
2. The function myPow takes a double x and an integer n as input.
3. We initialize a variable ans to 1.0 to store the result.
4. We use a for loop to multiply ans by x, n times.
5. The final result is returned as the value of ans.
*/