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
// class Solution {
// public:
//     unordered_map<int, vector<pair<TreeNode*, int>>> maps;
    

//     void dfs(TreeNode* root, int x, int y){
//         if(root == NULL){
//             return;
//         }
//         maps[x].push_back(root);
//         dfs(root->right, x+1, y+1);
//         dfs(root->right, x-1, y-1);
//     }
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root == NULL){
//             return ans;
//         }
        
//         // get size of map
//         // loop over map -> get min key and max key
//         // loop from min key to max key and for each key, see if it exists in the map 
//         // now get values -> do something similar 
        
        
//         dfs(root, 0, 0);
        
//         int num_keys = maps.size();
//         int max_key = INT_MIN, min_key = INT_MAX;
//         unordered_map<int, pair<int,int>> ranges;
//         for(auto key:maps){
//             if(key.first<min_key){
//                 min_key = key;
//             }
//             if(key.first>max_key){
//                 max_key = key;
//             }
//         }
        
//         for(int i= min_key;i<=max_key;i++){
//             if(maps.find(i) == maps.end()){
//                 continue;
//             }
            
            
//         }
        
//         return ans;
        
//     }
// };

// the following is nlogn solution

class Solution {
    vector<vector<int>>res;
    map<int, map<int, vector<int>>>mp;
    void dfs(TreeNode* root, int l, int h) {
        if (!root) return;
        
        mp[l][h].push_back(root->val);
        dfs(root->left, l-1, h+1);
        dfs(root->right, l+1, h+1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return res;
        dfs(root, 0, 0);
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            auto m = it->second;
            vector<int>col;
            for (auto t = m.begin(); t != m.end(); t++) {
                vector<int>v = t->second;
                for (auto i = 0; i < v.size(); i++)
                    col.push_back(v[i]);
            }
            res.push_back(col);
        }   
        return res;
    }
};