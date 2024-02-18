class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // cumsum based solution
        unordered_map<int, int> counts;
        counts[0] = -1;
        int maxlen = 0, count = 0;
        for(int i=0;i<nums.size();i++){
            count = count + (nums[i] == 0? -1: 1);
            if(counts.find(count) != counts.end()){
                maxlen = max(maxlen, i - counts[count]);
            }
            else{
                counts[count] = i;
            }
        }
        return maxlen;
    }
};