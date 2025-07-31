#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans) {
    int n = mat.size();

    // Boundary conditions
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] != 1) {
        return;
    }

    // Destination reached
    if (r == n - 1 && c == n - 1) {
        ans.push_back(path);
        return;
    }

    // Mark as visited
    mat[r][c] = -1;

    // Explore all directions
    solve(mat, r + 1, c, path + 'D', ans); // Down
    solve(mat, r, c + 1, path + 'R', ans); // Right
    solve(mat, r - 1, c, path + 'U', ans); // Up
    solve(mat, r, c - 1, path + 'L', ans); // Left

    // Backtrack (unmark cell)
    mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;

    int n = mat.size();
    if (n == 0 || mat[0][0] == 0 || mat[n - 1][n - 1] == 0) {
        return ans; // No valid path
    }

    solve(mat, 0, 0, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> ans = findPath(mat);

    if (ans.empty()) {
        cout << "No path found." << endl;
    } else {
        cout << "Paths from top-left to bottom-right:" << endl;
        for (const string &path : ans) {
            cout << path << endl;
        }
    }

    return 0;
}
