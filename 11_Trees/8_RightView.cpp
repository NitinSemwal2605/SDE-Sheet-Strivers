#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val) {
            data = val;
            left = NULL;
            right = NULL;
        }
};

vector<int> RightView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        result.push_back(q.front()->data);

        while (n--) {
            Node* current = q.front();
            q.pop();

            // Push right child first to ensure rightmost node is processed first
            if (current->right) {
                q.push(current->right);
            }
            if (current->left) {
                q.push(current->left);
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
    root->right->right = new Node(6);

    vector<int> rightView = RightView(root);
    
    for (int val : rightView) {
        cout << val << " ";
    }
    
    return 0;
}
// TC - O(N)
// where N is the number of nodes in the tree.

// SC - O(N) for queue and result storage
// where N is the number of nodes in the tree.