#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows); // 2D vector to store the triangle

    for(int i =0 ; i< numRows ; i++){
        r[i].resize(i+1); // Resize each row to hold i+1 elements
        r[i][0] = r[i][i] = 1; // First and last element of each row is 1

        for(int j=1 ; j<i;j++){
            r[i][j] = r[i-1][j-1]+r[i-1][j]; // Fill in the middle elements
        }  
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> res = generate(n);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}


// Time Complexity: O(n^2)
// Space Complexity: O(1) for the triangle itself