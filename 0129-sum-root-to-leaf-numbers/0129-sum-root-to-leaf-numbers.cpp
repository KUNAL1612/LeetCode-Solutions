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

// leaf = any non null node that has no children
// root = specified node that is the root of the tree

class Solution {
public:
    
    int ans; 
    
    void dfs(TreeNode* root, int temp){
        if(root==NULL){
            return;
        }
        temp=temp*10+root->val;
        if(root->left==NULL && root->right==NULL){
            
            ans+=temp;
            return;
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
        
        
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};