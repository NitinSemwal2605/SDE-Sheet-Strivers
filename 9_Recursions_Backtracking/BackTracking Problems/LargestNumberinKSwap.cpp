#include <bits/stdc++.h>
using namespace std;

void solve(string& s, int k, string& res, int start) {
    if (k == 0) {
        res = max(res, s);
        return;
    }

    int n = s.length();
    res = max(res, s);

    for (int i = start; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] < s[j]) { // Only swap if it increases value
                swap(s[i], s[j]);
                solve(s, k - 1, res, i + 1);
                swap(s[i], s[j]); // backtrack
            }
        }
    }
}

string findMaximumNum(string s, int k) {
    string res = s;
    solve(s, k, res, 0);
    return res;
}

int main() {
    string s;
    int k;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the number of swaps allowed: ";
    cin >> k;

    string result = findMaximumNum(s, k);
    cout << "Largest number after " << k << " swaps is: " << result << endl;

    return 0;
}

// Time Complexity: O(n^2 * k) -> n^2 for all pairs and k for swaps
// Space Complexity: O(n) -> for the result string