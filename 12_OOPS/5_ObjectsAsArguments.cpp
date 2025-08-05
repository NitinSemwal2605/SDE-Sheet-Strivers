#include <bits/stdc++.h>
using namespace std;

class Time {
    int hours;
    int minutes;
    public:
    void getData(int h, int m){
        hours = h;
        minutes = m;
    }
    void putData(void) {
        cout << "Time: " << hours << " hours and " << minutes << " minutes" << endl;
    }
    void Sum(Time , Time); // Function to sum two Time objects
};

void Time::Sum(Time t1, Time t2) {
    minutes = t1.minutes + t2.minutes;
    hours = t1.hours + t2.hours + (minutes / 60);
    minutes = minutes % 60;
}

int main() {
    Time t1, t2, t3;
    int h1, m1, h2, m2;

    cout << "Enter first time (hours and minutes): ";
    cin >> h1 >> m1;
    t1.getData(h1, m1);

    cout << "Enter second time (hours and minutes): ";
    cin >> h2 >> m2;
    t2.getData(h2, m2);

    t3.Sum(t1, t2);

    cout << "First ";
    t1.putData();
    cout << "Second ";
    t2.putData();
    cout << "Sum ";
    t3.putData();

    return 0;
}