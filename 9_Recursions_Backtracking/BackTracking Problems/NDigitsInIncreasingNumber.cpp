#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& V, vector<int>& result) {
    if (n == 0) {
        int num = 0;
        for (int digit : V) {
            num = num * 10 + digit;
        }
        result.push_back(num);
        return;
    }

    int start = V.empty() ? 1 : V.back() + 1; // Starting from 1 or the next digit after the last added digit
    for (int i = start; i <= 9; i++) {
        V.push_back(i);
        solve(n - 1, V, result);
        V.pop_back();
    }
}

vector<int> increasingNumbers(int n) {
    vector<int> result;
    if (n == 1) {
        for (int i = 1; i <= 9; i++) {
            result.push_back(i);
        }
        return result;
    }

    vector<int> V;
    solve(n, V, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans = increasingNumbers(n);
    for (int num : ans) {
        cout << num << " ";
    }
    return 0;
}
