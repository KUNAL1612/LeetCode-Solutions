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
    vector<int> inorder;
    int k;
    double target;
    void dfs(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
        
    }
    
    vector<int> findClosestElements() {
        vector<int>& arr = inorder;
        // Initialize binary search bounds
        int left = 0;
        int right = arr.size() - k;

        // Binary search against the criteria described
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target - arr[mid] > arr[mid + k] - target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
    
//     Here's my one-liner intuition for it: you can rearrange x - arr[mid] > arr[mid + k] - x to be x > (arr[mid] + arr[mid + k]) / 2. That is, we're asking "is x greater than the midpoint between arr[mid] and arr[mid + k]?", or equivalently "is x closer to arr[mid + k] than arr[mid]"?

        // Create output in correct format
        vector<int> result(arr.begin() + left, arr.begin() + left + k);

        return result;
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        this->k = k;
        this->target = target;
        dfs(root);
        vector<int> temp = findClosestElements();
        return temp;
        
    }
};