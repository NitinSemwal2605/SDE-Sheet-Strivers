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
    vector<int> result;
    if (!root) return result;

    stack<Node*> nodes;
    stack<int> flag; // 0 = first time, 1 = visited

    nodes.push(root);
    flag.push(0);

    while (!nodes.empty()) {
        Node* curr = nodes.top();
        int visit = flag.top();
        nodes.pop();
        flag.pop();

        if (!curr) continue;

        if (visit == 1) {
            result.push_back(curr->data);
        } else {
            // Push in reverse order: right, self (visited), left
            if (curr->right) {
                nodes.push(curr->right);
                flag.push(0);
            }

            nodes.push(curr);
            flag.push(1); // Mark as visited

            if (curr->left) {
                nodes.push(curr->left);
                flag.push(0);
            }
        }
    }

    return result;
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
