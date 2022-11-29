class Solution {

public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        auto N = s.size();
        auto M = wordDict.size();
        if (N == 0 || M == 0) return false;

        vector<bool> dp(N + 1, false);dp[0] = true;
        for (int i = 0; i < N; ++i) {
            if(!dp[i]){
                continue;
            }
            for(auto& str : wordDict) {  //this is a good way to iterate through a vector
                int len = str.size();
                if(dp[i]) {
                    if(s.substr(i,len) == str) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        return dp[N];
    }
};