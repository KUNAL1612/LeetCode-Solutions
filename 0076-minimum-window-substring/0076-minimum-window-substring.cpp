class Solution {
public:
    string minWindow(string s, string t) {
        // explanation at https://www.youtube.com/watch?v=eS6PZLjoaq8 
        int l = 0, r = 0, st = 0, len = INT_MAX;
        int n = s.length(), m = t.length();
        if ( n == 0 || m == 0)
            return "";
        
        unordered_map<char, int> dict;
        for (auto c : t){
            dict[c]++;
        }
        
        
        int count = m;
        while (r < n){
            dict[s[r]]--;
            if (dict[s[r]] >= 0) {
                count--;
            }
            r++;
            while (count == 0){
                if(len > r - l){
                    st = l;
                    len = r - l;
                }
                dict[s[l]]++;
                if(dict[s[l]] > 0) {
                    count++;
                }
                l++;
            }
        }
        
        return len < INT_MAX? s.substr(st, len) : "";
    }

};