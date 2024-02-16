class Solution {
public:
    string removeDuplicates(string s, int k) {
    vector<int> count(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
        if (i == 0 || s[i] != s[i - 1]) {
            count[i] = 1;
        } else {
            count[i] = count[i - 1] + 1;
            if (count[i] == k) {
                s.erase(i - k + 1, k);
                i = i - k; // only need to check for k before the deleted sequence. Anything prior has not been changed and we have checked for it already. 
            }
        };
    }
    return s;
    }
};