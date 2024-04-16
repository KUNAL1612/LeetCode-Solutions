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
    vector<int> ans;
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        //does this node have a single child
        if(root->left == NULL && root->right!=NULL){
            ans.push_back(root->right->val);
        }
        
        if(root->left != NULL && root->right==NULL){
            ans.push_back(root->left->val);
        }
        
        dfs(root->left);
        dfs(root->right);
        
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return ans;
            
    }
};