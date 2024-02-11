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
    
    
    
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        vector<TreeNode*> h;
        h.push_back(root);
        h.push_back(NULL);
        int lm=INT_MIN;
        
        for(int i=0;i<h.size();i++){
            if(h[i]==NULL){
                //current level is over
                ans.push_back(lm);
                lm=INT_MIN; 
                if(h.size()-i==1){
                    break;
                }
                h.push_back(NULL);
                continue;
                
            }
            TreeNode* temp=h[i];
            lm=max(lm,temp->val);    
            if(temp->left!=NULL){
                h.push_back(temp->left);
            }
            if(temp->right!=NULL){
                h.push_back(temp->right);
            }
            
        }
        return ans;
    }
};