#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    int SIZE = 1000;
    vector<list<pair<int, int>>> table;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() : table(SIZE) {}

    void put(int key, int value) {
        int index = hash(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update existing value
                return;
            }
        }
        table[index].emplace_back(key, value); // Insert new key-value pair
    }

    int get(int key) {
        int index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return the value if key is found
            }
        }
        return -1; // Return -1 if key is not found
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it); // Remove the key-value pair
                return;
            }
        }
    }

    void clear() {
        for (auto& bucket : table) {
            bucket.clear();
        }
    }
};

int main() {
    MyHashMap hashMap;

    hashMap.put(1, 1); // Insert key-value pair (1, 1)
    hashMap.put(2, 2); // Insert key-value pair (2, 2)
    cout << hashMap.get(1) << endl; // Returns 1
    cout << hashMap.get(3) << endl; // Returns -1 (not found)
    hashMap.put(2, 3); // Update key 2 with value 3
    cout << hashMap.get(2) << endl; // Returns 3
    hashMap.remove(2); // Remove key 2
    cout << hashMap.get(2) << endl; // Returns -1 (already removed)

    return 0;
}