#include<bits/stdc++.h>
using namespace std;

int max_size;

//constructing tree top-down with this utility
int constructTreeUtil(int arr[], int left, int right, int *tree, int v){

    if(left == right) {
        tree[v] = arr[left];
        return arr[left];
    }


    int mid = (left + right)/2;
    tree[v] = constructTreeUtil(arr, left, mid, tree, v*2+1) + 
                constructTreeUtil(arr, mid+1, right, tree, v*2+2);
    return tree[v];
}

//main tree function to be called from main for tree construction
int* tree(int arr[], int n){

    //height of the tree
    int height = (int)(ceil(log2(n)));

    //max size of the segment tree
    max_size = 2*(int)pow(2,height)-1;

    int* st = new int[max_size];

    constructTreeUtil(arr, 0, n-1, st, 0);

    cout<<"Orignal Tree\n";
    for(int i=0;i<=max_size;i++) cout<<st[i]<<" ";
    cout<<endl;

    return st;
}

//recursive function to be called to resolve the range query sum
int getSumUtil(int tree[], int treeleft, int treeright, int left, int right, int v) {

    //if this egment is the part of the given range, return the sum
    if(left <= treeleft && right >= treeright) 
        return tree[v];

    //the required segment is outside the required range
    if(right < treeleft || left > treeright) 
        return 0;

    int mid = (treeleft + treeright)/2;
    return getSumUtil(tree, treeleft, mid, left, right, 2*v+1) + 
            getSumUtil(tree, mid+1, treeright, left, right, 2*v+2);

}

//function to be called from main for getting the sum within the range left, right
int getSum(int tree[], int n, int left, int right){
    if(left < 0 || right > n-1 || left > right){
        cout<<"Invalid Input\n"; 
        return -1;
    }

    return getSumUtil(tree, 0, n-1, left, right, 0);
}

void updateValueUtil(int *tree, int treeleft, int treeright, int idx, int diff, int v){
    //if index lies outside the range
    if(idx > treeright || idx < treeleft) return;

    //update the values in the tree node
    tree[v] = tree[v] + diff;

    if(treeleft != treeright) {
        int mid = (treeleft + treeright)/2;
        updateValueUtil(tree, treeleft, mid, idx, diff, 2*v+1);
        updateValueUtil(tree, mid+1, treeright, idx, diff, 2*v+2);
    }

}

// function to be called from main, to update value in the segment tree
void updateValue(int *arr, int *tree, int n, int idx, int nVal){

    //input checks
    if(idx > n-1 || idx < 0) {
        cout<<"Invalid index\n";
        return;
    } 

    int diff = nVal - arr[idx];

    arr[idx] = nVal;

    updateValueUtil(tree, 0, n-1, idx, diff, 0);

    cout<<"Updated tree :\n";
    for(int i=0;i<=max_size;i++) cout<<tree[i]<<" ";
    cout<<endl;
}

// void printTree(int tree[], int treeleft, int treeright){
//     for(int i=0;i<treeright; i++) cout<<tree[i]<<" ";
//     cout<<"\n";
// }


int main()
{
    int n = 10;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    
    //build tree
    int *root = tree(arr, n);

    //print tree
    // printTree(root, 0, 4*n);

    //sum in a range
    cout<<getSum(root, n, 1, 6)<<endl;

    //update a value
    updateValue(arr, root, n, 4, 15);

    //sum of the range with updated value
    cout<<getSum(root, n, 1, 6)<<endl;

    return 0;
}
