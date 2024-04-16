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
    
    void dfs(TreeNode* root, int v, int d, int c_d){
        if(root==NULL){
            return;
        }
        if(c_d==d-1){
            TreeNode* a=root->left;
            root->left=new TreeNode(v);
            root->left->left=a;
            a=root->right;
            root->right=new TreeNode(v);
            root->right->right=a;
        }
        else{
            dfs(root->left,v,d,c_d+1);
            dfs(root->right,v,d,c_d+1);
        }
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* a=new TreeNode(v);
            a->left=root;
            return a;
        }
        dfs(root, v, d, 1);
        return root;
    }
};