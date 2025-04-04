#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pivot = -1;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    reverse(nums.begin() + pivot + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

/*
Dry Run:
Input: nums = [1, 2, 3]
Output: nums = [1, 3, 2]

step 1: Find the first decreasing element from the right so that we can swap it with the next greater element.
        i = 1, nums[i] = 2, nums[i+1] = 3
        i = 0, nums[i] = 1, nums[i+1] = 2
        i = -1, no decreasing element found.
step 2: Find the next greater element to swap with nums[i].
        j = 2, nums[j] = 3, nums[i] = 1
step 3: Swap nums[i] and nums[j].
        nums = [3, 2, 1]
step 4: Reverse the elements after i.
        nums = [1, 3, 2]
step 5: Return the result.
*/