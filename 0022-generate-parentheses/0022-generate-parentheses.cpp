class Solution {
public:
    void helper(string current, int open, int close, vector<string>& answer, int n){
        if(current.size()==2*n){
            answer.push_back(current);
            return;
        }
        if(open<n){
            current.push_back('(');
            helper(current, open+1, close, answer, n);
            current.pop_back();
            
        }
        if(close<open){
            current.push_back(')');
            helper(current, open, close+1, answer, n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("", 0, 0, ans, n);
        return ans;
    }
};