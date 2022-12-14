class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        int cnt = 0, l = 0, r = tokens.size()-1;
        while(l<=r){
            if(tokens[l] <= P){
                cnt++;
                P -= tokens[l++];
            }
            else if(r-l>1 && cnt>0){
                P += tokens[r--];
                cnt--;
            }
            else
                break;
        }
        return cnt;
    }
};