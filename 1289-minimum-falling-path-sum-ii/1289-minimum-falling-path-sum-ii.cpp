class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        for(int i=0;i<n;i++){dp[0][i]=A[0][i];}
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int ans=INT_MAX;
                for(int k=0;k<n;k++){
                    if(k==j){
                        continue;
                    }
                    ans=min(ans,dp[i-1][k]);
                }
                int y=A[i][j];
                dp[i][j]=ans+y;
            }
                
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            ans=min(ans,dp[m-1][i]);
        }
        
        return ans;
    }
};