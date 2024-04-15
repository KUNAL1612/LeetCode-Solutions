class Solution {
public:
    std::vector<int> partitionLabels(std::string S) {
        std::vector<int> last(26, 0);
        for (int i = 0; i < S.length(); ++i)
            last[S[i] - 'a'] = i;
        
        int j = 0, anchor = 0;
        std::vector<int> ans;
        for (int i = 0; i < S.length(); ++i) {
            j = std::max(j, last[S[i] - 'a']);
            if (i == j) {
                ans.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }
        return ans;
    }
};