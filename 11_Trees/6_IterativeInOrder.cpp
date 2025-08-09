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

vector<int> InOrder(Node* root) {
    stack <Node*> s;
    stack<bool> visited;
    s.push(root);
    visited.push(0);
    vector<int>ans;

    while (!s.empty()) {
        Node *temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();

        if(!flag){
            if(temp->right) {
                s.push(temp->right);
                visited.push(0);
            }
            s.push(temp);
            visited.push(1);
            if(temp->left) {
                s.push(temp->left);
                visited.push(0);
            }
        } else {
            ans.push_back(temp->data);
        }
    }
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = InOrder(root);
    cout << "InOrder Traversal: ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
