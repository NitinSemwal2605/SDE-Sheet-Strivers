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

Node* Tree(int* in, int* pre, int Instart, int Inend, int& preIndex) {
    // Base case
    if (Instart > Inend) {
        return nullptr;
    }

    Node* root = new Node(pre[preIndex]);
    preIndex++;

    // If this node has no children
    if (Instart == Inend) {
        return root;
    }

    // Find the position of this root in inorder
    int pos = find(in, root->data, Instart, Inend);

    // Recur for left and right subtrees
    root->left = Tree(in, pre, Instart, pos - 1, preIndex);
    root->right = Tree(in, pre, pos + 1, Inend, preIndex);

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
    int pre[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(in) / sizeof(in[0]);
    int preIndex = 0;

    Node* root = Tree(in, pre, 0, n - 1, preIndex);

    cout << "Inorder Traversal of Constructed Tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
