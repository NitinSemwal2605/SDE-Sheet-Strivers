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

vector<int>VerticalTraversal(Node*root){
    int l=0, r=0;
    find(root, 0, l, r);
    vector<vector<int>>Positive(r+1);
    vector<vector<int>>Negative(abs(l)+1);
    queue<Node*>q;
    queue<int>index;

    q.push(root);
    index.push(0);

    while(!q.empty()){
        Node* curr=q.front();
        int col=index.front();
        q.pop();
        index.pop();

        if(col>=0) Positive[col].push_back(curr->data);
        else Negative[abs(col)].push_back(curr->data);

        if(curr->left){
            q.push(curr->left);
            index.push(col-1);
        }
        if(curr->right){
            q.push(curr->right);
            index.push(col+1);
        }
    }

    vector<int>result;
    for(int i=Negative.size()-1;i>=0;i--){
       for(int j=0;j<Negative[i].size();j++){
           result.push_back(Negative[i][j]);
       }
    }
    for(int i=0;i<Positive.size();i++){
       for(int j=0;j<Positive[i].size();j++){
           result.push_back(Positive[i][j]);
       }
    }

    return result;
}

void find(Node* root, int col, int& l, int& r) {
    if (!root) return;
    l = min(l, col);
    r = max(r, col);
    find(root->left, col - 1, l, r);
    find(root->right, col + 1, l, r);
}

int main (){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    vector<int> result = VerticalTraversal(root);
    for (int x : result) cout << x << " ";
    return 0;
}
