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

vector<vector<int>> PreInPost(Node* root) {
    vector<int> pre, in, post;
    if (root == NULL) {
        return {pre, in, post};  // Return empty vectors if root is null
    }

    stack<pair<Node*, int>> st; // <Node*, stage> (Stage means 1: Preorder, 2: Inorder, 3: Postorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        Node* node = it.first;
        int stage = it.second;

        if (stage == 1) {
            pre.push_back(node->data);      // Preorder
            st.push({node, 2});
            if (node->left) {
                st.push({node->left, 1});
            }
        } else if (stage == 2) {
            in.push_back(node->data);       // Inorder
            st.push({node, 3});
            if (node->right) {
                st.push({node->right, 1});
            }
        } else {
            post.push_back(node->data);     // Postorder
        }
    }

    return {pre, in, post};
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = PreInPost(root);
    cout << "Preorder: ";
    for (int val : result[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for (int val : result[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int val : result[2]) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}