#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    if (n == 0) {
        return;
    }
    cout << arr[0] << " ";
    printArray(arr + 1, n - 1); 
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    return 0;
}