#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int find(int *in, int val, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == val) {
            return i;
        }
    }
    return -1;
}

Node* Tree(int* in, int* post, int Instart, int Inend, int& postIndex) {
    // Base case
    if (Instart > Inend) {
        return nullptr;
    }

    Node* root = new Node(post[postIndex]);
    postIndex--;

    // If this node has no children
    if (Instart == Inend) {
        return root;
    }

    // Find the position of this root in inorder
    int pos = find(in, root->data, Instart, Inend);

    // Recur for right and left subtrees
    root->right = Tree(in, post, pos + 1, Inend, postIndex);
    root->left = Tree(in, post, Instart, pos - 1, postIndex);

    return root;
}

void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int in[] = {4, 2, 5, 1, 6, 3};
    int post[] = {4, 5, 2, 6, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);
    int postIndex = n - 1;

    Node* root = Tree(in, post, 0, n - 1, postIndex);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
