#include <bits/stdc++.h>
using namespace std;

void permute(string ip, string op , vector<string>&v){
    if(ip.length() == 0){
        v.push_back(op);
        return;
    }

    unordered_set<char> seen;
    for(int i = 0; i < ip.length(); i++){
        if(seen.find(ip[i]) == seen.end()){
            seen.insert(ip[i]);
            string newIp = ip.substr(0, i) + ip.substr(i + 1);
            permute(newIp, op + ip[i], v);
        }
    }
}

int main() {
    string ip;
    cout << "Enter the string: ";
    cin >> ip;

    vector<string> v;
    permute(ip, "", v);

    cout << "Permutations are: " << endl;
    for(const auto& str : v) {
        cout << str << endl;
    }

    return 0;
}

// Time Complexity: O(n!)
// Space Complexity: O(n * n!) -> reason (storing all permutations in a vector)