#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void rightViewUtil(Node* root, int level, vector<int>& result) {
    if (root == NULL) return;

    // If this is the first node of its level
    if (level == result.size()) {
        result.push_back(root->data);
    }

    // Recur for right and left subtrees
    rightViewUtil(root->right, level + 1, result);
    rightViewUtil(root->left, level + 1, result);
}

vector<int> RightView(Node* root) {
    vector<int> result;
    rightViewUtil(root, 0, result);
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> rightView = RightView(root);
    
    for (int val : rightView) {
        cout << val << " ";
    }
    
    return 0;
}
