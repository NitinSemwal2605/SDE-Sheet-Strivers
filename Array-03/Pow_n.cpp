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