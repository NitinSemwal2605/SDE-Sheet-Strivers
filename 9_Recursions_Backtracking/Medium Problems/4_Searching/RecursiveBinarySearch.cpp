#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
    if (left > right){
        cout << "Element not found" << endl;
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == key){
        cout << "Element found at index: " << mid << endl;
        return mid;
    }

    if (arr[mid] < key){
        return binarySearch(arr, mid + 1, right, key);
    }

    return binarySearch(arr, left, mid - 1, key);
}

int main(){
    int arr[100];
    int n, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> key;

    binarySearch(arr, 0, n - 1, key);
    return 0;
}