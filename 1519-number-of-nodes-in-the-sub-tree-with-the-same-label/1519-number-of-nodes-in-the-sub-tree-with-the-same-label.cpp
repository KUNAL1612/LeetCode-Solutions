class Solution {
public:
  vector<int> result;
  
  vector<int> helper(vector<vector<int>> &g, string &labels, int i){
    vector<int> ans(26, 0);
    result[i] = 1;
    ans[labels[i] - 'a'] = 1;
    
    for(int j = 0; j != g[i].size(); j++)
      if(!result[g[i][j]]){
        vector<int> tmp = helper(g, labels, g[i][j]);
        for(int k = 0; k != 26; k++) ans[k] += tmp[k];
      }
    
    result[i] = ans[labels[i] - 'a'];
    
    return ans;
  }
  
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<vector<int>> g(n);
    result.resize(n,0);
    
    for(int i = 0; i != edges.size(); i++){
        
      g[edges[i][0]].push_back(edges[i][1]); 
      g[edges[i][1]].push_back(edges[i][0]);
    }
    
    helper (g, labels, 0);
    return result;
  }
};