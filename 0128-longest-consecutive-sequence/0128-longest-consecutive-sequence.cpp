
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int maxSeq = 0; // Initialize maxSeq
        for(auto& num : s) {
            if(s.find(num-1) == s.end()) {
                int seqLen = 0;
                int num_to_check = num;
                while(s.find(num_to_check) != s.end()) {
                    num_to_check++;
                    seqLen++;
                }
                maxSeq = max(maxSeq, seqLen);
            }
        }
        return maxSeq; 
    }
};
