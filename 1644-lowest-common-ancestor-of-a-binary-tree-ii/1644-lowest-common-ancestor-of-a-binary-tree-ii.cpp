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
    bool isPpresent = false;
    bool isQpresent = false;
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return NULL;
        }
         TreeNode* L = lca(root->left, p, q);
        TreeNode* R = lca(root->right, p, q);
        
        
        // this is important, we need to the full recursion instead of just pruning it.
       
        if(root == p){
            isPpresent = true;
            return root;
        }

        if(root == q){
            isQpresent = true;
            return root;
        }
        if(L==NULL){return R;}
        if(R==NULL){return L;}
        
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* val = lca(root, p, q);
        if(val!=NULL && (isPpresent && isQpresent)){
            return val;
        }
        return NULL;
    }
};

// 