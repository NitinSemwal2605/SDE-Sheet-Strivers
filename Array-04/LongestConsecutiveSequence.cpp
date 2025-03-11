#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.empty())  return 0;

    sort(nums.begin(), nums.end());

    int longestStreak = 1;
    int currentStreak = 1;

    for (int i =1;i<nums.size();++i){
        if(nums[i] != nums[i-1]){
            if(nums[i] == nums[i-1] +1 ){
                currentStreak ++ ;
            }
            else{
                longestStreak = max(longestStreak, currentStreak);
                currentStreak =1 ;
            }
        }
    }
    return max(longestStreak, currentStreak);
}

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}
// Time Complexity: O(nlogn) + O(n) = O(nlogn)