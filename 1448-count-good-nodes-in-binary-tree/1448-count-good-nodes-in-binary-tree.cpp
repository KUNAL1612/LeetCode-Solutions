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
    int ans=0;
    void dfs(TreeNode* root, int max_so_far){
        if(root==NULL){
            return;
        }
        if(root->val>=max_so_far){
            ans++;
            max_so_far=root->val;
        }
        
        dfs(root->right, max_so_far);
        dfs(root->left, max_so_far);
        
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        ans++;
        dfs(root->left, root->val);
        dfs(root->right, root->val);
        return ans;
    }
};