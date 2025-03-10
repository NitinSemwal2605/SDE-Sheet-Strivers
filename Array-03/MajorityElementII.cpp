#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mpp;
    vector<int> res;
    
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    for(auto x:mpp){
        if(x.second>n/3){
            res.push_back(x.first);
        }
    }
    return res;
}

int main() {
    vector<int> nums = {3,2,3};
    vector<int> res = majorityElement(nums);
    for(auto x:res){
        cout << x << " ";
    }
    return 0;
}