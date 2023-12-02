class Solution{
    public:
        int jump(vector<int> nums){
            if(nums.size()<=1){
                return 0;
            }
            int n=nums.size();
            vector<int> dp(n,0);
            int j=0 , i=1;
            while(i<n){
                if(i<=j+nums[j]){
                    dp[i]=dp[j]+1;
                    i++;
                    
                    // we go as far out as possible. And then we only check for the next best number that can take us further. No point checking anything we have already covered.
                }
                else{
                    j++;
                }
            }
            return dp[n-1];
        }
};