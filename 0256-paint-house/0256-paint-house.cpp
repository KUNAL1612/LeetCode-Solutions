class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int houses=costs.size();
        int colors=costs[0].size();
        vector<vector<int>> dp(houses, vector<int> (colors,0));
        for(int i=0;i<colors;i++){
            dp[houses-1][i]=costs[houses-1][i];
        }
        for(int i=houses-2;i>=0;i--){
            
            for(int j=0;j<colors;j++){
                int m=INT_MAX; 
                for(int k=0;k<colors;k++){
                    if(k==j){
                        continue;
                    }
                    m=min(m,costs[i][j]+dp[i+1][k]);
                }
                dp[i][j]=m;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<colors;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};