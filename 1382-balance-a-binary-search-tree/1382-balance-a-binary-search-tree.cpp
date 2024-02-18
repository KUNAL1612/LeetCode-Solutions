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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vInorder {};
        traverseInorder(root, vInorder); // convert BST to vector
        sort(begin(vInorder), end(vInorder)); // sort vector (already sorted??)
        int size = vInorder.size();
        return constructBST(vInorder, 0, size - 1); // consctruct a balanced BST
        
    }
private:
    void traverseInorder(TreeNode* root, vector<int>& v) {
        if (!root)
            return;
		traverseInorder(root->left, v);
        v.push_back(root->val);
        traverseInorder(root->right, v);
    }
    
    TreeNode* constructBST(vector<int>& v, int start, int end) {
        if (start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = constructBST(v, start, mid - 1);
        root->right = constructBST(v, mid + 1, end);
        return root;
    }
};