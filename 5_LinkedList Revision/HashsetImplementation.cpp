#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    int SIZE = 1000;
    vector<list<int>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() : table(SIZE) {}

    void add(int key) {
        int index = hash(key);
        for (int val : table[index]) {
            if (val == key) {
                return;
            }
        }
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        for (int val : table[index]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    MyHashSet hashSet;

    hashSet.add(1);
    hashSet.add(2);
    cout << hashSet.contains(1) << endl; // returns true
    cout << hashSet.contains(3) << endl; // returns false (not found)
    hashSet.add(2);
    cout << hashSet.contains(2) << endl; // returns true
    hashSet.remove(2);
    cout << hashSet.contains(2) << endl; // returns false (already removed)

    return 0;
}