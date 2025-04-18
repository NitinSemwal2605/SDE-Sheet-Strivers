#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int N = matrix.size();
    int M = matrix[0].size();
    int row_index, col_index;
    int start = 0;
    int end = N * M - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        row_index = mid / M;
        col_index = mid % M;

        if (matrix[row_index][col_index] == target) {
            return 1;
        } else if (matrix[row_index][col_index] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    cout << searchMatrix(matrix, target) << endl;
    return 0;
}