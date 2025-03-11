#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& arr) {
    unordered_map<int,int> mp; // Sum : Index
    
    int sum =0;
    int ans =0;
    mp[0] = -1;
    
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        
        if(mp.find(sum)!= mp.end()){
            ans = max(ans , i-mp[sum]);
        }else{
            mp[sum] = i;
        }
    }
    
    return ans;
}

int main(){
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<maxLen(arr)<<endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Approach: Create a map to store the sum and its index. If the sum is already present in the map, then the subarray with sum 0 is from the index+1 to the current index.
          If the sum is not present in the map, then store the sum and its index in the map.
*/