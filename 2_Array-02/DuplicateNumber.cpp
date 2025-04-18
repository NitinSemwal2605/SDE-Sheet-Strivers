#include <bits/stdc++.h>
using namespace std;

// Floyd's Tortoise and Hare Algorithm
int findDuplicate(vector<int>& nums) {
    int fast = nums[0];
    int slow = nums[0];

    while (fast != slow) {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }

    fast = nums[0];
    while (fast != slow) {
        fast = nums[fast];
        slow = nums[slow];
    }

    return slow;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << findDuplicate(nums) << endl;
    return 0;
}
