#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size(); 

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
Approach:
1. Sort the intervals based on the starting time.
2. Initialize an empty vector ans to store the merged intervals.
3. Iterate through the sorted intervals:
   - If ans is empty or the current interval does not overlap with the last merged interval, add it to ans.
   - If there is an overlap, merge the current interval with the last merged interval by updating the end time.
4. Return the merged intervals stored in ans.


Dry Run :  [[1, 3], [2, 6], [8, 10], [15, 18]]

1. Sort the intervals: [[1, 3], [2, 6], [8, 10], [15, 18]]
2. Initialize ans as an empty vector.
3. Start iterating through the sorted intervals:
   - i = 0: ans is empty, so add [1, 3] to ans.
   - i = 1: [2, 6] overlaps with [1, 3], so merge them to get [1, 6].
   - i = 2: [8, 10] does not overlap with [1, 6], so add it to ans.
   - i = 3: [15, 18] does not overlap with [8, 10], so add it to ans.
4. Final ans: [[1, 6], [8, 10], [15, 18]]
*/