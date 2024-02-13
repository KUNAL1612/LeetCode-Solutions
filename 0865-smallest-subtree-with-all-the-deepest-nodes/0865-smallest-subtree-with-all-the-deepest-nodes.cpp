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
    unordered_map<TreeNode*, int> depth;
    int max_depth;

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth[NULL] = -1;
        dfs(root, NULL);

        max_depth = -1;
        for (auto d : depth)
            max_depth = max(max_depth, d.second);

        return answer(root);
    }

    void dfs(TreeNode* node, TreeNode* parent) {
        if (node != NULL) {
            depth[node] = depth[parent] + 1;
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }

    TreeNode* answer(TreeNode* node) {
        if (node == NULL || depth[node] == max_depth)
            return node;

        TreeNode* L = answer(node->left);
        TreeNode* R = answer(node->right);

        if (L != NULL && R != NULL)
            return node;
        if (L != NULL)
            return L;
        if (R != NULL)
            return R;
        return NULL;
    }
};

 // get left depth, get right depth
// if either is greater than the 