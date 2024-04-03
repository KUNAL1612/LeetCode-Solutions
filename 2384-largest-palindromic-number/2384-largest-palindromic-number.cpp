class Solution {
public:
    string largestPalindromic(string num) {
        int freq[10] = {0};
        for(char ch: num) {
            freq[ch - '0']++;
        }
        string prefix = "";
        int centre = -1;
        for(int i = 9; i >= 0; i--) {
            while(freq[i] > 1) {
                prefix += ('0' + i);
                freq[i] -= 2;
            }
            if(freq[i] == 1) centre = max(centre, i);
        }
        string middle = "";
        if(centre != -1) middle = '0' + centre;
        if(prefix[0] == '0') {
            if(centre == -1) return "0";
            return middle;
        }
        string suffix(prefix.rbegin(), prefix.rend());
        return prefix + middle + suffix;
    }
};