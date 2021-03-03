// Constructing AVL tree from a given array (in any order)

#include<bits/stdc++.h>
using namespace std;

// Tree node
class Node {
    public:
    int data;
    int height;
    Node* left;
    Node* right;
};

// function to create new node and assign value
Node* newNode(int value) {
    Node* temp = new Node();
    temp->data = value;
    temp->height = 0; // all entries are in leaf nodes, and hence those will have zero height
    temp->left = temp->right = NULL;
    
    return temp;
}

// Function to get the height of the node
int subtreeHeight (Node *root) {
    if(!root) return 0;
    else return root->height;
}

int maxi(int a, int b) {
    return (a>b)?a:b;
}

// function to check imbalance of a node
int balanceFact (Node* node) {
    if(!node) return 0;
    return abs(subtreeHeight(node->left) - subtreeHeight(node->right));
}

// Right rotation function
Node* rightRotate(Node * node) {
    
    Node *al = node->left;
    Node *alr = node->left->right;
    
    // rotations
    al->right = node;
    node->left = alr;
    
    // updating heights
    node->height = max(subtreeHeight(node->left), subtreeHeight(node->right)) + 1;
    al->height = max(subtreeHeight(al->right), subtreeHeight(al->left)) + 1;
    
    return al;
}


// Left rotation function
Node* leftRotate(Node* node)
{
    Node *ar = node->right;
    Node *arl = node->right->left;
    
    // rotations
    ar->left = node;
    node->right = arl;
    
    // updating heights
    node->height = maxi(subtreeHeight(node->right), subtreeHeight(node->left)) + 1;
    ar->height = maxi(subtreeHeight(ar->right),subtreeHeight(ar->left)) + 1;
    
    return ar;
}

// AVL utility function to insert nodes one by one into the tree 
// and then, if node becomes imbalance perform rotations
Node* BSTutil(Node* root, int key) {
  
//   1. Normal BST operation
   
    if(!root) 
        return newNode(key);
    
    if(key>(root->data))
        root->right = BSTutil(root->right, key);
        
    else if(key<(root->data))
        root->left = BSTutil(root->left, key);

    else return root;
    
    // 2. Updating height of this ancestor node
    root->height = 1 + max(subtreeHeight(root->left), subtreeHeight(root->right));
    
    // 3. check if this node becomes unbalanced
    // Since this is under recursion, each and everynode will get its balance Factor checked
    int balance = balanceFact(root);
    
    
    // If the node is imbalanced, there are 4 cases to regain balance:
    
    // Left Left case --> right rotate
    if(balance > 1 && key < root->left->data) return rightRotate(root);
    
    // Right Right case --> left rotate
    if(balance > 1 && key > root->right->data) return leftRotate(root);
    
    // Left Right case --> right then left rotate
    if(balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Right Left case --> right then left rotate
    if(balance > 1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// inorder traversal
void inorderBSTtraversal(Node* root) {
    if(!root) return;
    
    if(root->left) inorderBSTtraversal(root->left);
    cout<<root->data<<" ";
    if(root->right) inorderBSTtraversal(root->right);
}

// preorder traversal
void preorderAVLtraversal(Node* root) {
    if(!root) return;
    cout<<root->data<<" ";
    preorderAVLtraversal(root->left);
    preorderAVLtraversal(root->right);
}

// main driver function
int main()
{
    cout<<"Creating an AVL tree :\n\n";
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<"Tree created! \n\n";
    
    Node* root = NULL;
    for(int i=0;i<n;i++) root = BSTutil(root, arr[i]);
    
    cout<<"Inorder Traversal of the AVL tree :\n";
    inorderBSTtraversal(root);
    
    cout<<"\n\n";
    cout<<"Preorder Traversal of the AVL tree : \n";
    preorderAVLtraversal(root);
    
    cout<<"\n\n";
    
    // test code for checking individual node values manually --------------
    // cout<<root->left->left->data;
    // cout<<root->left->data;
    
    return 0;
}
