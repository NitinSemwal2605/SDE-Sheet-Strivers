#include <iostream>
using namespace std;

int TotalSum(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[0] + TotalSum(arr + 1, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Total Sum: " << TotalSum(arr, n) << endl;
    return 0;
}