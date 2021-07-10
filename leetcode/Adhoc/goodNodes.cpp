// Question : https://leetcode.com/problems/count-good-nodes-in-binary-tree/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void DFS(TreeNode *root, int mx, int &count) {
        if(root->val >= mx ) {
            count++;
            mx = root->val;
        }
        
        if(root->left != NULL) DFS(root->left, mx, count);  
        if(root->right != NULL) DFS(root->right, mx, count);
        
    }
  
    int goodNodes(TreeNode* root) {
        
        //DFS with a maxNum variable
        
        int maxNum = INT_MIN, count = 0;
        DFS(root, maxNum, count);
        return count;
        
    }
};
