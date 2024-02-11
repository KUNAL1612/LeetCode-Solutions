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


class CBTInserter {
private:
    TreeNode* root;
    deque<TreeNode*> deque;

public:
    CBTInserter(TreeNode* root) : root(root) {
        queue<TreeNode*> queue;
        queue.push(root);

        // BFS to populate deque
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            if (node->left == nullptr || node->right == nullptr)
                deque.push_back(node);
            if (node->left != nullptr)
                queue.push(node->left);
            if (node->right != nullptr)
                queue.push(node->right);
        }
    }

    int insert(int v) {
        TreeNode* node = deque.front();
        deque.push_back(new TreeNode(v));
        if (node->left == nullptr)
            node->left = deque.back();
        else {
            node->right = deque.back();
            deque.pop_front();
        }

        return node->val;
    }

    TreeNode* get_root() {
        return root;
    }
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */