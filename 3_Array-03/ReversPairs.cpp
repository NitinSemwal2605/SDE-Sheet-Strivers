#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;      
        int right = mid + 1; 

        // Store elements in sorted 
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Remaining left elements .
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Remaining Right elements .
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);         // left half
        cnt += mergeSort(arr, mid + 1, high);    // right half
        cnt += countPairs(arr, low, mid, high);  // count reverse pairs
        merge(arr, low, mid, high);              // merge sorted halves
        return cnt;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << solution.reversePairs(nums) << endl;
    return 0;
}