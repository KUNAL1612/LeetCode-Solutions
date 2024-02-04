class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> eleme_counts;
        for(auto& num:nums){
            eleme_counts[num]++;
        }
        int max_count = 0;
        int max_leme;
        for(const auto& pair: eleme_counts){
            if(pair.second>max_count){
                max_count = pair.second;
                max_leme = pair.first;
            }
        }
        return max_leme;
    }
};