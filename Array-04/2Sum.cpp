#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        int num = nums[i];
        int moreneeded = target-num;
        if(mpp.find(moreneeded) != mpp.end()){  // it means mpp[moreneeded] is present in the map
            return {mpp[moreneeded] , i};
        }
        mpp[num] = i;
    }
    return {-1,-1};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> ans = twoSum(nums,target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
} 


/*
nums : [2,7,11,15]
target : 9

mpp : {2:0, 7:1, 11:2, 15:3}
Step 1 :
    i = 0, num = 2, moreneeded = 9-2 = 7
    mpp.find(7) != mpp.end() => false
    mpp[2] = 0
Step 2 :
    i = 1, num = 7, moreneeded = 9-7 = 2
    mpp.find(2) != mpp.end() => true
    return {0,1}
*/