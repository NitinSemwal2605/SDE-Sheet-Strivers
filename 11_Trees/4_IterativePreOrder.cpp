#include <bits/stdc++.h>
using namespace std;

class Node{
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

vector<int> PreOrder(Node*root){
    vector<int>PreOrder;
    if(root == nullptr) return PreOrder;
    stack<Node*>s;
    s.push(root);

    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        PreOrder.push_back(curr->data);
        
        // Push right child first so that left child is processed first
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
    return PreOrder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = PreOrder(root);
    
    for(int val : result) {
        cout << val << " ";
    }
    
    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

/*
Approach :
    1. Use a stack to keep track of nodes.
    2. Start with the root node, push it onto the stack.
    3. While the stack is not empty:
        a. Pop the top node from the stack.
        b. Add its value to the result vector.
        c. Push the right child onto the stack (if it exists).
        d. Push the left child onto the stack (if it exists).
    4. Return the result vector containing the preorder traversal.
*/