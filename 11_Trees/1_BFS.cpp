#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

   queue<Node *> q;
    q.push(root);
    Node *temp;
    while (!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left){
            q.push(temp->left);
        }
        if (temp->right){
            q.push(temp->right);
        }
    }

    return 0;
}