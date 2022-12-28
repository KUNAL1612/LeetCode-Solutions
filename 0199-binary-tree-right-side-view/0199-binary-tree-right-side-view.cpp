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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        TreeNode* t;
        queue<TreeNode*> q1;
        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            TreeNode* temp=q1.front();
            q1.pop();
            if(temp==NULL){
                ans.push_back(t->val);
                if(q1.size()>0){
                    q1.push(NULL);
                }
            }
            else{
                t=temp;
                if(temp->left!=NULL){q1.push(temp->left);}
                if(temp->right!=NULL){q1.push(temp->right);}
            }
        }
        return ans;
    }
};