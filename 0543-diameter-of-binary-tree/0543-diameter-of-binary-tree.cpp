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
    int longest=INT_MIN;
    
    int md(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        
        int l=md(root->left);
        int r=md(root->right);
        longest=max(longest,l+r+1);
        return max(l,r)+1;
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        md(root);
        
        return longest-1;
    }
};