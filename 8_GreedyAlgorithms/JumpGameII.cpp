// Jump Game - II ( Minimum Jumps to Reach the End )
#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int jumps = 0, currentEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size() - 1; i++) { // No need to jump from the last index
        farthest = max(farthest, i + nums[i]);
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps to reach the end: " << jump(nums) << endl;
    return 0;
}

