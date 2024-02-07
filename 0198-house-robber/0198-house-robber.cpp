class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // int last_even,last_odd;
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=max(nums[1], dp[0]);
        for(int i=2;i<n;i++){
            int max_loot_at_i=0;
            // for(int j=0;j<i-1;j++){
            max_loot_at_i=max(dp[i-1], dp[i-2]+nums[i]);
            // }
            dp[i]=max_loot_at_i;
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};