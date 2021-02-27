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

node *constructTree(int pre[], int *preIndex,int key, int min, int max, int size) {
    
    if(*preIndex >= size) return NULL;
    
    node *root = NULL;
    
    if(key>min && key<max) {
        root = newNode(key);
        *preIndex += 1;
        
        if(*preIndex<size) root->left = constructTree(pre, preIndex, pre[*preIndex], min, key, size);
        
        if(*preIndex<size) root->right = constructTree(pre, preIndex, pre[*preIndex], key, max, size);
    }

    
    return root;
}


node* Tree(int pre[], int size) {
    int preIndex = 0;
    return constructTree(pre, &preIndex,pre[0], INT_MIN, INT_MAX, size);
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
