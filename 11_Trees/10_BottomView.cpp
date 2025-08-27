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

vector<int> BottomView(Node* root) {
    vector<int> ans;
    if(!root) return ans;
    map<int,int> mpp;
    queue<pair<Node*,int>> q;

    q.push({root, 0});
    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        Node* curr = temp.first;
        int hd = temp.second;
        q.pop();

        mpp[hd] = curr->data;

        if (curr->left) {
            q.push({curr->left, hd - 1});
        }
        if (curr->right) {
            q.push({curr->right, hd + 1});
        }
    }

    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}

int main(){
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