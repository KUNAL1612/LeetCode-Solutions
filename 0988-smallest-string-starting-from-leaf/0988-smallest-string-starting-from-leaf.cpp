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
    string ans= "";
    void dfs(TreeNode* root, string soFar){
        if(root == NULL){
            return;
        }
        char curr = 'a' + root->val;
        if(root->left == NULL && root->right == NULL){
            if(ans == ""){
                string temp = soFar+curr;
                reverse(temp.begin(), temp.end());
                ans = temp;
            }
            else{
                string temp = soFar+curr;
                reverse(temp.begin(), temp.end());
                ans = min(ans, temp);    
            }
            
        }
        
        dfs(root->left, soFar + curr);
        dfs(root->right, soFar + curr);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};