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


/*
Approach : 1. Using HashMap
           2. Store the sum of elements in the map and their index
           3. If the sum is already present in the map, then we have found a subarray with sum 0
           4. Update the answer with the maximum length of the subarray
           5. Return the answer
*/