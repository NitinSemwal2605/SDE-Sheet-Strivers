#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

long long sumN(int n) { // Sum of first n natural numbers
    if (n <= 1) return n;
    return n + sumN(n - 1);
}

long long power(int base, int exponent) { // Calculate base^exponent
    if (exponent == 0) return 1;
    return base * power(base, exponent - 1);
}

long long sumOfSquares(int n) { // Sum of squares of first n natural numbers
    if (n <= 1) return 1;
    return n * n + sumOfSquares(n - 1);
}

int main() {
    int n, base, exponent;

    cout << "Enter a number : ";
    cin >> n;

    cout << "Factorial of " << n << " is: " << factorial(n) << endl;
    cout << "Sum of first " << n << " natural numbers is: " << sumN(n) << endl;
    cout << "Sum of squares of first " << n << " natural numbers is: " << sumOfSquares(n) << endl;

    cout << "\nEnter base and exponent for power calculation: ";
    cin >> base >> exponent;
    cout << base << "^" << exponent << " = " << power(base, exponent) << endl;

    return 0;
}
