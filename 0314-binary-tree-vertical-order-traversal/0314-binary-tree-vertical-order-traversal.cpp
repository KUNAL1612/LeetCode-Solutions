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
    unordered_map<int, unordered_map<int, vector<int>>> maps;
    int min_x = INT_MAX;
    int max_x = INT_MIN;
    
    int min_y = INT_MAX;
    int max_y = INT_MIN;
    

    void dfs(TreeNode* root, int x, int y){
        if(root == NULL){
            return;
        }
        min_x = min(min_x,x);
        max_x = max(max_x,x);
        min_y = min(min_y,y);
        max_y = max(max_y,y);
        maps[x][y].push_back(root->val);
        dfs(root->left, x-1, y+1);
        dfs(root->right, x+1, y+1);
        
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        // get size of map
        // loop over map -> get min key and max key
        // loop from min key to max key and for each key, see if it exists in the map 
        // now get values -> do something similar 
        
        
        dfs(root, 0, 0);
        
        vector<vector<int>> answer;
        for(int i= min_x;i<=max_x;i++){
            if(maps.find(i) == maps.end()){
                continue;
            }
            vector<int> temp;
            for(int j = min_y;j<=max_y;j++){
                temp.insert(temp.end(), maps[i][j].begin(), maps[i][j].end());
            }
            answer.push_back(temp);
            
            
        }
        
        
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
//             ranges[key] = make_pair
//         }
        
//         for(int i= min_key;i<=max_key;i++){
//             if(maps.find(i) == maps.end()){
//                 continue;
//             }
            
            
//         }
        
        return answer;
        
    }
};

// the following is nlogn solution

// class Solution {
//     vector<vector<int>>res;
//     map<int, map<int, vector<int>>>mp;
//     void dfs(TreeNode* root, int l, int h) {
//         if (!root) return;
        
//         mp[l][h].push_back(root->val);
//         dfs(root->left, l-1, h+1);
//         dfs(root->right, l+1, h+1);
//     }
// public:
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         if (!root) return res;
//         dfs(root, 0, 0);
        
//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             auto m = it->second;
//             vector<int>col;
//             for (auto t = m.begin(); t != m.end(); t++) {
//                 vector<int>v = t->second;
//                 for (auto i = 0; i < v.size(); i++)
//                     col.push_back(v[i]);
//             }
//             res.push_back(col);
//         }   
//         return res;
//     }
// };