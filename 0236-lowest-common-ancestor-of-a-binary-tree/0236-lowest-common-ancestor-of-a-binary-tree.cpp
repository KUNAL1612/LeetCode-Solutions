/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recurse(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
        
        
        
        TreeNode* left= recurse(root->left,p,q);
        TreeNode* right= recurse(root->right,p,q);
        // this is important, we need to the full recursion instead of just pruning it.
        if(root==p || root==q){     
            return root;
        }
        
        if(left==NULL){return right;}
        if(right==NULL){return left;}
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recurse(root,p,q);
        
    }
};


// another way to do it 