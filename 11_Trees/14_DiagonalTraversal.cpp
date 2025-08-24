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

void find(Node*root, int pos , int &l){
    if(!root) return;
    l = min(l, pos);
    find(root->left, pos + 1, l);
    find(root->right, pos, l);
}

void findDig(Node* root, int diag, vector<vector<int>>& ans) {
    if (!root) return;
    ans[diag].push_back(root->data);
    findDig(root->left, diag + 1, ans);
    findDig(root->right, diag, ans);
}

vector<int> DiagonalTraversal(Node* root) {
    int l =0;
    find(root, 0, l);
    vector<vector<int>> ans(l + 1);
    findDig(root, 0, ans);
    vector<int> result;
    for (auto& vec : ans) {
        result.insert(result.end(), vec.begin(), vec.end());
    }
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> result = DiagonalTraversal(root);
    for (int x : result) cout << x << " ";
    return 0;
}