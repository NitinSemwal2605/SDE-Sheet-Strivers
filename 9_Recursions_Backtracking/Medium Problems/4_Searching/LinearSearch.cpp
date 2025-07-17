#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int key, int index = 0) {
    if (index >= n) {
        return -1;
    }
    if (arr[index] == key) {
        return index;
    }
    return linearSearch(arr, n, key, index + 1);
}

int main(){
    int arr[100];
    int n, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> key;

    int result = linearSearch(arr, n, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}