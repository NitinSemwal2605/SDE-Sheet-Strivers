#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

vector<int> LevelOrder(Node *root){
    vector<int> ans;
    if (root == NULL){
        return ans;
    }
    queue<Node *> q;
    q.push(root);
    Node *temp;
    while (!q.empty()){
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->left){
            q.push(temp->left);
        }
        if (temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = LevelOrder(root);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}