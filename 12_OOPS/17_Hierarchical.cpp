#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "Eating...\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking...\n";
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "Meowing...\n";
    }
};

int main() {
    Dog d;
    Cat c;
    d.eat();
    d.bark();
    c.eat();
    c.meow();
    return 0;
}
