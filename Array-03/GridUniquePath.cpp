#include <bits/stdc++.h>
using namespace std;

long long binomialCoefficient(int m, int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (m - n + i);
        result /= i;
    }
    return result;
}

int uniquePaths(int m, int n) {
    int totalSteps = m + n - 2;
    int downSteps = min(m - 1, n - 1);
    return binomialCoefficient(totalSteps, downSteps);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    return 0;
}