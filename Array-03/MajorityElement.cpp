#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int,int> mpp;
    
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    for(auto x:mpp){
        if(x.second>n/2){
            return x.first;
        }
    }
    return 0;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}