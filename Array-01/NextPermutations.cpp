#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int i = nums.size()-2;
    // First Decreasing from Right
    while(i >= 0 && nums[i] >= nums[i + 1]){ 
        i--;
    }
    if (i >= 0) {
        int j = nums.size() - 1;
        // Element to Swap
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    // Reverse
    reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}