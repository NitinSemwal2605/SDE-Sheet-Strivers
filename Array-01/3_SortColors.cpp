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

