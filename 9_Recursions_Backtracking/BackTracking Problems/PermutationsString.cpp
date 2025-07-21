#include <bits/stdc++.h>
using namespace std;

void Permute(string &s , int start , vector<string> &v) {
    if (start == s.length() - 1) {
        v.push_back(s);
        return;
    }

    unordered_set<char> seen;
    for (int i = start; i < s.length(); i++) {
        if (seen.find(s[i]) == seen.end()) {
            seen.insert(s[i]);
            swap(s[start], s[i]);
            Permute(s, start + 1, v);
            swap(s[start], s[i]); // backtrack
        }
    }
}


int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<string> v;
    Permute(s, 0, v);

    cout << "Permutations are: " << endl;
    for (const auto &str : v) {
        cout << str << endl;
    }

    return 0;
}

// Time Complexity: O(n!)
// Space Complexity: O(n * n!) -> reason (storing all permutations in a vector