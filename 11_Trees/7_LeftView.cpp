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

vector<int> Leftview(Node* root) {
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

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
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

    vector<int> leftView = Leftview(root);
    
    for (int val : leftView) {
        cout << val << " ";
    }
    
    return 0;
}


// TC - O(N)
// SC - O(N) for queue and result storage