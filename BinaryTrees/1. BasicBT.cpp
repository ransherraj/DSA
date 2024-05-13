// Pre Order Traversal

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data){
        val = data;
    }
};


void solve(Node * root){
    if(root == NULL) return;
    cout<<root->val<<endl;
    solve(root->left);
    solve(root->right);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(11);
    root->left->left = new Node(3);
    root->right->left = new Node(9);
    root->left->right = new Node(4);
    
    solve(root);
}

// Ans

/*
4, Col: 1 (539 selected)
 Command Line Arguments
   
10
5
3
4
11
9





*/
