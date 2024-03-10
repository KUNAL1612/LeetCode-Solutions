class Solution {
public:
    int ans=0;
    int dfs(vector<vector<int>>& matrix, int i, int j, int pre, vector<vector<int>>& dp){
        
        if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()){
            return 0;
        }
        else if(pre>=matrix[i][j]){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        
        int na=matrix[i][j];
        
        int p1=dfs(matrix, i+1, j, na, dp);
        int p2=dfs(matrix, i-1, j, na, dp);
        int p3=dfs(matrix, i, j+1, na, dp);
        int p4=dfs(matrix, i, j-1, na, dp);
        
        dp[i][j]=max(max(p1,p2),max(p3,p4))+1;
        return dp[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        // for each number, we find a path starting from that number
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==0){
                    dfs(matrix,i,j,INT_MIN, dp);  //taking INT_MIN so that even 1 is acting as a starting 
                    ans=max(ans,dp[i][j]);
                }
                
            }
        }
        return ans;
    }
};