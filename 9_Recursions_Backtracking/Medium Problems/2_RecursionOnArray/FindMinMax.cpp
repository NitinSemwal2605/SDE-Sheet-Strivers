#include <iostream>
using namespace std;

int Mini(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return min(arr[0], Mini(arr + 1, n - 1));
}

int Maxi(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    return max(arr[0], Maxi(arr + 1, n - 1));
}

int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Minimum Element: " << Mini(arr, n) << endl;
    cout << "Maximum Element: " << Maxi(arr, n) << endl;
    
    return 0;
}