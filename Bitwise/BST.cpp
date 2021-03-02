// Constructing Binary Search Tree from a given array

#include<bits/stdc++.h>
using namespace std;

// Tree node
class Node {
    public:
    int data;
    Node* left;
    Node* right;
};

// function to create new node and assign value
Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    
    return temp;
}

// BST utility function to insert nodes one by one into the tree
Node* BSTutil(Node* root, int val) {
    if(!root) 
        return newNode(val);
    
    if(val>(root->data))
        root->right = BSTutil(root->right, val);
        
    else if(val<(root->data))
        root->left = BSTutil(root->left, val);

    return root;
}

// inorder traversal
void inorderBSTtraversal(Node* root) {
    if(!root) return;
    
    if(root->left) inorderBSTtraversal(root->left);
    cout<<root->data<<" ";
    if(root->right) inorderBSTtraversal(root->right);
    
}

// main driver function
int main()
{
    cout<<"Creating a BST\n\n";
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    Node* root = NULL;
    for(int i=0;i<n;i++) root = BSTutil(root, arr[i]);
    
    cout<<"This traversal must give an increasing sequence for a correctly constructed tree \n";
    
    inorderBSTtraversal(root);
    
    // For testing each branch specifically ------------
    // cout<<(root->right->left)->data;
    // cout<<(root->right)->data;
    
    // Getting a SIGSEGV in console, means
    // that particular node doesn't exist (is NULL a node)

    return 0;
}
