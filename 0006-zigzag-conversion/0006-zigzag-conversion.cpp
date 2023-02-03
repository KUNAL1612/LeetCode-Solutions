class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        vector<vector<char>> strs(numRows);        
        bool downDirection = true;
        int r = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            strs[r].push_back(s[i]);
            if (downDirection) {
                ++r;
                if (r == numRows - 1)
                    downDirection = false;
            } else {
                --r;
                if (r == 0)
                    downDirection = true;
            }
        }
        
        string ret("");
        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < strs[i].size(); ++j) {
                ret += strs[i][j];
            }
        }
        
        return ret;
    }
};