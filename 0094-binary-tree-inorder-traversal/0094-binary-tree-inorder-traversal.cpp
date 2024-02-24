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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                res.push_back(curr->val);
                curr = curr->right; // move to next right node
            } else { // has a left subtree
                pre = curr->left;
                while (pre->right != nullptr) { // find rightmost
                    pre = pre->right;
                }
                pre->right = curr; // put curr after the pre node
                TreeNode* temp = curr; // store curr node
                curr = curr->left; // move curr to the top of the new tree
                temp->left = nullptr; // original curr left be null, avoid infinite loops
            }
        }
        return res;
    }
};