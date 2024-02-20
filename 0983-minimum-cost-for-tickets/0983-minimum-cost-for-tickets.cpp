class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(366, INT_MAX);
        dp[0] = 0;
        unordered_set<int>travel(days.begin(), days.end());
        
        for (int i = 1; i < dp.size(); i++) {
            if (travel.find(i) == travel.end())
                dp[i] = dp[i-1];
            else {
                dp[i] = min({costs[0] + dp[i-1], costs[1] + dp[max(0, i-7)], costs[2] + dp[max(0, i-30)]});
            }
        }
        
        return dp[365];
    }
};