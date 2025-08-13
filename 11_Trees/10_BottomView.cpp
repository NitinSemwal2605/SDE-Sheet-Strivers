#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
}; 

vector<int> BottomView(Node* root) {
    if (!root) return {};

    // Map to store the bottom view
    map<int, int> mpp;
    queue<pair<Node*, int>> q; // Pair of Node and its horizontal distance from root

    q.push({root, 0});

    while (!q.empty()) {
        pair<Node*, int> frontPair = q.front();
        Node* node = frontPair.first;
        int hd = frontPair.second; // horizontal distance
        q.pop();

        // Update the bottom view map
        mpp[hd] = node->data;

        // Push left child with horizontal distance - 1
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        // Push right child with horizontal distance + 1
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    vector<int> result;
    for (map<int, int>::iterator it = mpp.begin(); it != mpp.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    vector<int> bottomView = BottomView(root);
    for (int val : bottomView) {
        cout << val << " ";
    }
    return 0;
}