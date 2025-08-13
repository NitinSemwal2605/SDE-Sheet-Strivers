#include <bits/stdc++.h>
using namespace std;

class Sample{
    int a;
    int b;
    
    public:
    void setData(int x, int y) {
        a = x;
        b = y;
    }
    friend float mean(Sample s1, Sample s2); // Friend function is used to access private members.
};

float mean(Sample s1, Sample s2) {
    return (s1.a + s1.b + s2.a + s2.b) / 4.0;
}

int main() {
    Sample s1, s2;
    int x1, y1, x2, y2;

    cout << "Enter first pair of integers (x1 y1): ";
    cin >> x1 >> y1;
    s1.setData(x1, y1);

    cout << "Enter second pair of integers (x2 y2): ";
    cin >> x2 >> y2;
    s2.setData(x2, y2);

    float result = mean(s1, s2);
    cout << "Mean of the two pairs is: " << result << endl;

    return 0;
}

/*
    Conclusion:
    1. Friend functions can access private and protected members of a class.
    2. They are not members of the class but have access to its private data.
    3. Useful for operator overloading and when two or more classes need to work together.
*/