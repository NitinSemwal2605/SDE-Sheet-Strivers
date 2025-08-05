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

vector<int> iterativePostOrder(Node* root) {
    stack<Node*> s;
    vector<int> PostOrder;
    if (root == nullptr) return PostOrder;

    s.push(root);
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        PostOrder.push_back(current->data);

        // Push left child first so that right child is processed first
        if (current->left) {
            s.push(current->left);
        }
        if (current->right) {
            s.push(current->right);
        }
    }

    reverse(PostOrder.begin(), PostOrder.end()); // Get correct post-order
    return PostOrder;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> postOrderResult = iterativePostOrder(root);

    cout << "Post-order traversal: ";
    for (int val : postOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
