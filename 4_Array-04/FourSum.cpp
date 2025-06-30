#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n - 3; i++) {
        // duplicate first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            // duplicate  second element
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            long long target_sum = (long long)target - nums[i] - nums[j]; 
            int start = j + 1;  
            int end = n - 1;
            
            while (start < end) {
                int sum = nums[start] + nums[end];
                
                if (sum == target_sum) {
                    result.push_back({nums[i], nums[j], nums[start], nums[end]});
                    
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;
                    
                    start++;
                    end--;
                } else if (sum < target_sum) {
                    start++;
                } else {
                    end--;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> result = fourSum(nums, target);
    
    for (const auto& quadruplet : result) {
        cout << "[" << quadruplet[0] << ", " << quadruplet[1] << ", " << quadruplet[2] << ", " << quadruplet[3] << "]" << endl;
    }
    
    return 0;
}


/*

Approach :
1. Sort the array.
2. Iterate through the array, fixing two elements at a time.
3. For each fixed pair, use two pointers to find pairs that sum to the target minus the sum of the fixed elements.
4. Skip duplicates to avoid repeated quadruplets.
5. Store the unique quadruplets in a result vector.
*/
