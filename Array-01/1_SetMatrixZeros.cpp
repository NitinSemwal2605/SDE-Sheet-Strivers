#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<bool> rows(n, false); 
    vector<bool> cols(m, false); 

    // First pass which rows and columns have zeros
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                rows[i] = true; // Mark the row
                cols[j] = true; // Mark the column
            }
        }
    }

    // Second pass set rows to zero
    for (int i = 0; i < n; ++i) {
        if (rows[i]) {
            for (int j = 0; j < m; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Third pass  set columns  zero
    for (int j = 0; j < m; ++j) {
        if (cols[j]) {
            for (int i = 0; i < n; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}