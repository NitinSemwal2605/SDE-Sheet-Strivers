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

    void display() {
        cout << "Movie Name: " << name << ", Rating: " << rating << endl;
    }
};

int main() {
    Movie m1("Inception", 5);
    Movie m2("Interstellar", 4);

    m1.display();
    m2.display();

    return 0;
}