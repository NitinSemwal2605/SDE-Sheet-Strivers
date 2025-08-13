#include <bits/stdc++.h>
using namespace std;

class Movie{
    string name;
    int rating;

public:
    Movie(string n, int r) {
        name = n;
        rating = r;
    }

    // Copy constructor
    Movie(const Movie &m) {
        name = m.name;
        rating = m.rating;
    }

    void display() {
        cout << "Movie Name: " << name << ", Rating: " << rating << endl;
    }
};

int main() {
    Movie m1("Inception", 5);
    Movie m2 = m1; // Calls copy constructor

    m1.display();
    m2.display();

    return 0;
}
