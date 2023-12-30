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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* next=NULL;
        while(root!=NULL){
            if(p->val>=root->val){
                root=root->right;
            }
            else{
                next=root;
                root=root->left;
            }
        }
        return next;
    }
};

// if the node itself is p then return p
/// if the node has p as right child then return p 
// if not