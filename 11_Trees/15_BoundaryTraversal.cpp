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

void printLeftBoundary(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printLeftBoundary(root->left);
}

void printRightBoundary(Node* root) {
    if (!root) return;
    printRightBoundary(root->right);
    cout << root->data << " ";
}

void printLeafNodes(Node* root) {
    if (!root) return;
    printLeafNodes(root->left);
    if (!root->left && !root->right) cout << root->data << " ";
    printLeafNodes(root->right);
}

void BoundaryTraversal(Node* root) {
    if (!root) return;
    cout << "Boundary Traversal: ";
    printLeftBoundary(root);
    printLeafNodes(root);
    printRightBoundary(root);
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    BoundaryTraversal(root);
    return 0;
}