#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> colors = {2, 0, 2, 1, 1, 0};

    sortColors(colors);

    cout << "Sorted colors: ";
    for (int color : colors) {
        cout << color << " ";
    }
    cout << endl;

    return 0;
}


/* Approach : 
    1. Initialize three pointers: low, mid, and high.
    2. low points to the next position for 0, mid is the current element, and high points to the last position for 2.
    3. Iterate through the array:
        - If nums[mid] is 0, swap it with nums[low], increment both low and mid.
        - If nums[mid] is 1, just increment mid.
        - If nums[mid] is 2, swap it with nums[high] and decrement high.
    4. Continue until mid exceeds high.
    5. The array is now sorted in place with all 0s, followed by 1s, and then 2s.
*/

/*
    Dry Run : [2, 0, 2, 1, 1, 0]
    Initial State: low = 0, mid = 0, high = 5
    Iteration 1: nums[mid] = 2
        Swap nums[mid] with nums[high]
        Array: [0, 0, 2, 1, 1, 2]
        high = 4
    Iteration 2: nums[mid] = 0
        Swap nums[mid] with nums[low]
        Array: [0, 0, 2, 1, 1, 2]
        low = 1, mid = 1
    Iteration 3: nums[mid] = 0
        Swap nums[mid] with nums[low]
        Array: [0, 0, 2, 1, 1, 2]
        low = 2, mid = 2
    Iteration 4: nums[mid] = 2
        Swap nums[mid] with nums[high]
        Array: [0, 0, 1, 1, 2, 2]
        high = 3
    Iteration 5: nums[mid] = 1
        Increment mid
        Array: [0, 0, 1, 1, 2, 2]
        mid = 3
    Iteration 6: nums[mid] = 1
        Increment mid
        Array: [0, 0, 1, 1, 2, 2]
        mid = 4
    End: low = 2, mid = 5, high = 3
    Final Array: [0, 0, 1, 1, 2, 2]
*/