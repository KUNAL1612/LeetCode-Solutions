class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> freq_count;
        int l=0, r=0;
        int max_length = 0;
        while(r < s.size()){
            freq_count[s[r]]++;
            while(freq_count.size() > k){
                freq_count[s[l]]--;
                if(freq_count[s[l]] == 0){
                    freq_count.erase(s[l]);
                }
                l++;
            }
            max_length = max(max_length, r - l + 1);
            r++;
        }
        return max_length;
    }
};