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
    int closestValue(TreeNode* root, double target) {
        int res;
        double mindiff=DBL_MAX;
        traverse(root,res,mindiff,target);
        return res;
    }
    
    void traverse(TreeNode* root, int& res, double&mindiff, double target){
        if(root==NULL) return ;
        traverse(root->left,res,mindiff,target);
        if(abs((double)root->val-target)<mindiff){
            mindiff=abs(root->val-target);
            res=root->val;
        }
        
        traverse(root->right,res,mindiff,target);
    }
};


// class Solution {
// public:
//     int closestValue(TreeNode* root, double target) {
//         std::deque<TreeNode*> stack;
//         long pred = LONG_MIN;

//         while (!stack.empty() || root != nullptr) {
//             while (root != nullptr) {
//                 stack.push_back(root);
//                 root = root->left;
//             }
//             root = stack.back();
//             stack.pop_back();

//             if (pred <= target && target < root->val)
//                 return std::abs(pred - target) <= std::abs(root->val - target) ? static_cast<int>(pred) : root->val;

//             pred = root->val;
//             root = root->right;
//         }
//         return static_cast<int>(pred);
//     }
// };