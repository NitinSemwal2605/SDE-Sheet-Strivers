#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*left , *right;

        Node(int value){
            data = value;
            left = right = NULL;
        }
};

void Preorder(Node*root){
    if(root == NULL){
        return;
    }
    cout << root->data;
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node*root){
    if(root == NULL){
        return;
    }
    Inorder(root->left);
    cout << root->data;
    Inorder(root->right);
}

void Postorder(Node*root){
    if(root == NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data;
}

int main (){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    cout << "Inorder: ";
    Inorder(root);
    cout << endl;
    cout << "Postorder: ";
    Postorder(root);
    return 0;
}