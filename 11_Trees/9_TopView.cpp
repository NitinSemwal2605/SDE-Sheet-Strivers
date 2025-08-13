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

// To find the leftmost and rightmost positions
void find(Node* root, int pos, int &left, int &right) {
    if (root == nullptr) return;

    // Update the leftmost and rightmost positions
    left = min(left, pos);
    right = max(right, pos);

    // Recur for left and right subtrees
    find(root->left, pos - 1, left, right);
    find(root->right, pos + 1, left, right);
}

vector<int> TopView(Node* root){
    int left = 0 , right = 0;
    find(root, 0, left, right);

    vector<int> ans (right - left + 1);
    vector<bool> filled (right - left + 1, 0);
    
    queue<Node*>q;
    queue<int> index;
    q.push(root);
    index.push(-left * left);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();

        // If not filled then fill the position
        if(!filled[pos]){
            filled[pos]=1;
            ans[pos] = temp->data;
        }

        // Push left child
        if(temp->left){
            q.push(temp->left);
            index.push(pos - 1);
        }
        // Push right child
        if(temp->right){
            q.push(temp->right);
            index.push(pos + 1);
        }
    }

    return ans;
}

int main (){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    vector<int> topView = TopView(root);
    for (int val : topView) {
        cout << val << " ";
    }
    return 0;
}