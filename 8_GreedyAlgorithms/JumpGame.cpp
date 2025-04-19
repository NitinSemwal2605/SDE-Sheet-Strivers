// Jump Game - I ( Will You Reach the End? )

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false; // Can't reach this index
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << (canJump(nums) ? "Can reach the end" : "Cannot reach the end") << endl;
    return 0;
}
