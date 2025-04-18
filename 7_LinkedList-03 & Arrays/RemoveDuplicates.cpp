#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i=0;
    int n=nums.size();
    for(int j=1;j<n;j++){
        if(nums[j] != nums[i]){
            nums[i+1]  = nums[j];
            i++;
        }
    }
    return i+1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4};
    int newLength = removeDuplicates(nums);
    
    cout << "New length: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}