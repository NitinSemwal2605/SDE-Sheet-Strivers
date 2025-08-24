#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void spiralOrder(Node* root) {
    if (!root) return;

    stack<Node*> s1; // left to right
    stack<Node*> s2; // right to left

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        // Print current level from s1 (left to right)
        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            cout << curr->data << " ";

            if (curr->left) s2.push(curr->left);
            if (curr->right) s2.push(curr->right);
        }

        // Print current level from s2 (right to left)
        while (!s2.empty()) {
            Node* curr = s2.top();
            s2.pop();
            cout << curr->data << " ";

            if (curr->right) s1.push(curr->right);
            if (curr->left) s1.push(curr->left);
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    spiralOrder(root);
    return 0;
}

/*
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            int index = leftToRight ? i : (size - 1 - i); 
            level[index] = curr->val;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(level); // Add current level to result
        leftToRight = !leftToRight; // Toggle direction
    }
    return result;
}
*/