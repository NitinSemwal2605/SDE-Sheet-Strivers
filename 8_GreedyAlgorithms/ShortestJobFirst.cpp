#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    int n = bt.size();
    sort(bt.begin(), bt.end());
    long long total= 0;
    long long Currwait = 0;
    for (int i = 0; i < n; i++) {
        total += Currwait + bt[i];
        Currwait += bt[i];
    }
    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> bt(n);
    for (int i = 0; i < n; i++) {
        cin >> bt[i];
    }
    cout << solve(bt) << endl;
    return 0;
}