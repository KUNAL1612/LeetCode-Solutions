class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int last_even,last_odd;
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int maex=0;
            for(int j=0;j<i-1;j++){
                maex=max(maex, dp[j]+nums[i]);
            }
            dp[i]=maex;
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};