class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixCount;
        prefixCount.push_back(0);
        unordered_map<int, int> prefixSumToCount;
        prefixSumToCount[0] = 1;
        int ans= 0;
        for(int i=0;i<nums.size();i++){
            prefixCount.push_back(prefixCount[i] + nums[i]);
            ans += prefixSumToCount[prefixCount[i+1] - k];
            prefixSumToCount[prefixCount[i+1]]++;
        }
        return ans;
        
    }
};

