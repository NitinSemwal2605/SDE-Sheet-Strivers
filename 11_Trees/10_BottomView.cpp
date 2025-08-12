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

void find(Node* root, int pos, int &left, int &right) {
    if (!root) return;
    left = min(left, pos);
    right = max(right, pos);
    find(root->left, pos - 1, left, right);
    find(root->right, pos + 1, left, right);
}

void Bview(Node* root, int pos, vector<int> &ans, vector<int> &level, int depth) {
    if (!root) return;

    // If first time visiting this horizontal distance or at greater depth
    if (depth > level[pos]) {
        level[pos] = depth;
        ans[pos] = root->data;
    }

    Bview(root->left, pos - 1, ans, level, depth + 1);
    Bview(root->right, pos + 1, ans, level, depth + 1);
}

vector<int> BottomView(Node* root) {
    int left = 0, right = 0;
    find(root, 0, left, right);

    vector<int> ans(right - left + 1);
    vector<int> level(right - left + 1, INT_MIN);

    Bview(root, -left, ans, level, 0);
    return ans;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    vector<int> bottomView = BottomView(root);
    for (int val : bottomView) {
        cout << val << " ";
    }
    return 0;
}
