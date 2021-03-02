// Source : https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
//BST from pre order traversal


#include<bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node *left, *right;
};

node *newNode(int data) {
    node *temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    
    return temp;
}

node *constructTree(int pre[], int *preIndex, int low, int high, int size) {
    
    if(*preIndex >= size || low > high) return NULL;
    
    node *root = newNode(pre[*preIndex]);
    *preIndex += 1;
    
    if(low == high ) return root;
    
    int i;
    for( i=low; i<=high; ++i) 
        if(pre[i]>root->data) break;
        
    root->left = constructTree(pre, preIndex, *preIndex, i-1, size);
    
    root->right = constructTree(pre, preIndex, i, high, size);
    
    return root;
}


node* Tree(int pre[], int size) {
    int preIndex = 0;
    return constructTree(pre, &preIndex, 0, size-1, size);
} 


void printInorder(node *root){
    if(!root) return;
    printInorder(root->left);
    cout<<root->data<< " ";
    printInorder(root->right);
}

int main()
{
    int pre[] = {5,8,9,10, 11,12,20};
    int size = sizeof(pre)/sizeof(pre[0]);
    node *root = Tree(pre, size);
    printInorder(root);
    
    return 0;
}
