#include <bits/stdc++.h>
using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    
    // SN and S2N 
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    
    // actual (S) and S2) 
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += A[i];
        S2 += (long long)A[i] * A[i];
    }

    // differences
    long long val1 = S - SN;  // X - Y
    long long val2 = S2 - S2N;  // X^2 - Y^2
    
    // Calculate X + Y 
    val2 /= val1;

    long long X = (val1 + val2) / 2;
    long long Y = X - val1;
    
    return {(int)X, (int)Y};
}

int main() {
    vector<int> A = {3, 1, 2, 5, 3};
    vector<int> result = repeatedNumber(A);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}