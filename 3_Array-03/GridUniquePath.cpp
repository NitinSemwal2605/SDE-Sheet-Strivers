#include <bits/stdc++.h>
using namespace std;

long long binomialCoefficient(int m, int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (m - n + i);  // m! / (m-n)!
        result /= i; // i! (to avoid large factorials)
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

/*
Approach:
1. The problem is to find the number of unique paths from the top-left corner to the bottom-right corner of a grid.
2. The grid has m rows and n columns.
3. The only allowed moves are to the right and down.
4. To reach the bottom-right corner, we need to make (m-1) down moves and (n-1) right moves.
5. The total number of moves is (m-1) + (n-1) = m + n - 2.
6. The number of unique paths can be calculated using the binomial coefficient:
   C(m+n-2, m-1) or C(m+n-2, n-1)
7. The binomial coefficient C(a, b) is calculated as a! / (b! * (a-b)!).
8. We can optimize the calculation of the binomial coefficient using a loop to avoid large factorials.
9. The function binomialCoefficient calculates C(m, n) using the formula:
   C(m, n) = m! / (n! * (m-n)!)
10. The function uniquePaths calculates the total number of unique paths using the binomial coefficient.
*/

