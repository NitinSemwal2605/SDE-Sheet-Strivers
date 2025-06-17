#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pivot = -1;
    int n = nums.size();
    // Find the first decreasing element from the right
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
    // If no such element is found, reverse the entire array
    if (pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    // Find the next greater element to swap with nums[pivot]
    for(int i = n - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) { 
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    // Reverse the elements after the pivot
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

/*Done */