class Solution {
public:
    // for min coins till target, we have amount in outer loop and coins in inner loop
    int coinChange(vector<int>& coins, int amount){
        
        if(coins.size()==0){
            return -1;
        }
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int u=INT_MAX;
            for(auto it:coins){
                if(i-it>=0 && dp[i-it]!=-1){
                    u=min(u,dp[i-it]+1);                    
                }
            }
            if(u!=INT_MAX){
                dp[i]=u;
                
            }
        }
        return dp[amount];
    }
};