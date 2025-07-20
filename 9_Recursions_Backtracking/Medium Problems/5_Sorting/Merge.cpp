#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start , int mid, int end){
    vector<int> temp(mid - start + 1);
    int left = start;
    int right = mid + 1;
    int index = 0;

    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left];
            left++;
            index++;
        } else {
            temp[index] = arr[right];
            right++;
            index++;
        }
    }
    while (left <= mid) {
        temp[index] = arr[left];
        left++;
        index++;
    }
    while (right <= end) {
        temp[index] = arr[right];
        right++;
        index++;
    }
    // Copying the sorted elements back to the original array
    for (int i = 0; i < temp.size(); i++) {
        arr[start + i] = temp[i];
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}