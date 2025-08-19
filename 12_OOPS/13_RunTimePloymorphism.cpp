#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { // virtual function -> Enables overriding in derived classes.
        cout << "Animal speaks\n";
    }

    virtual void walk() = 0; // pure virtual function -> Must be implemented by derived classes.
    virtual ~Animal() {} // virtual destructor -> Means derived classes can be properly cleaned up.
};

class Dog : public Animal {
public:
    void speak() override { // correct override -> Used for providing specific implementation in derived class
        cout << "Dog barks\n";
    }

    void walk() override {
        cout << "Dog walks on 4 legs\n";
    }
};

class Cat final : public Animal {
public:
    void speak() override {
        cout << "Cat meows\n";
    }

    void walk() override {
        cout << "Cat walks silently\n";
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); // Dog barks
    a1->walk();  // Dog walks

    a2->speak(); // Cat meows
    a2->walk();  // Cat walks

    delete a1;
    delete a2;
}
