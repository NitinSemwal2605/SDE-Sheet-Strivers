#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        int target = -nums[i];  // nums[i] + nums[j] + nums[k] == 0
        int start = i + 1;
        int end = n - 1;
        
        while (start < end) {
            int sum = nums[start] + nums[end];
            
            if (sum == target) {
                result.push_back({nums[i], nums[start], nums[end]});
                
                // Skip duplicates for the second and third
                while (start < end && nums[start] == nums[start + 1]) start++;
                while (start < end && nums[end] == nums[end - 1]) end--;

                start++;
                end--;
            } else if (sum < target) {
                start++;
            } else {
                end--;
            }
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    for (const auto& triplet : result) {
        cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]" << endl;
    }
    
    return 0;
}


/*
Approach :
1. Sort the array.
2. Iterate through the array, fixing one element at a time.
3. For each fixed element, use two pointers to find pairs that sum to the negative of the fixed element.
4. Skip duplicates to avoid repeated triplets.
5. Store the unique triplets in a result vector.
*/