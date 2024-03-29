class Solution {
    int ans = 0;
    void dfs(int i, vector<vector<int>> graph[], vector<int>& values, int maxTime, int val)
    {
        if(maxTime < 0)
            return;
        val += values[i]; 
        if(i == 0)
        {
            ans = max(ans, val);
        }
        int tmp = values[i];
        values[i] = 0;
        for(auto &v : graph[i])
            dfs(v[0], graph, values, maxTime-v[1], val);
        values[i] = tmp;
    }
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<int>> graph[n];
        for(vector<int> &vec : edges)
        {
            graph[vec[0]].push_back({vec[1],vec[2]}); // 2 is the weight. 0 and 1 are the nodes. 
            graph[vec[1]].push_back({vec[0],vec[2]});
        }
        dfs(0, graph, values, maxTime, 0);
        return ans;
    }
};

// 