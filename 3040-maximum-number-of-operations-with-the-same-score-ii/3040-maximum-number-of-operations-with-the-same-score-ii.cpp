class Solution {
public:
    int dp[2000][2000][3];
    int solve(int i,int j,int sumInd,vector<int>&nums,vector<int>&sum)
    {
        if(i>=j)return 0;
        
        if(dp[i][j][sumInd]!=-1)return dp[i][j][sumInd];
        int maxi=0;
        int sum1=nums[i]+nums[i+1];
        int sum2=nums[j-1]+nums[j];
        int sum3=nums[i]+nums[j];
        
        int Sum=sum[sumInd];
        if(Sum==sum1)
        {
            maxi=max(maxi,1+solve(i+2,j,sumInd,nums,sum));
        }
        if(Sum==sum2)
        {
            maxi=max(maxi,1+solve(i,j-2,sumInd,nums,sum));
        }
        if(Sum==sum3)
        {
            maxi=max(maxi,1+solve(i+1,j-1,sumInd,nums,sum));
        }
        return dp[i][j][sumInd]=maxi;
        
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int sum1=nums[0]+nums[1];
        int sum2=nums[n-2]+nums[n-1];
        int sum3=nums[0]+nums[n-1];
        vector<int>sum={sum1,sum2,sum3}; // you can only ever start with any of these numbers
        
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<3;i++)
            ans=max(ans,solve(0,n-1,i,nums,sum));
        return ans;
        
    }
};