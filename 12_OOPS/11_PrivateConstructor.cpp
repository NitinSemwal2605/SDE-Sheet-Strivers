#include <bits/stdc++.h>
using namespace std;

class Movie {
    string name;
    int rating;

    // Private constructor
    Movie(string n, int r) {
        name = n;
        rating = r;
    }

public:
    // Factory method with Static
    static Movie createMovie(string n, int r) {
        return Movie(n, r); // Means we can only create Movie objects through this method
    }

    void display() {
        cout << "Movie Name: " << name << ", Rating: " << rating << endl;
    }
};

int main() {
    Movie m1 = Movie::createMovie("Inception", 5);
    Movie m2 = Movie::createMovie("Interstellar", 4);

    m1.display();
    m2.display();

    return 0;
}