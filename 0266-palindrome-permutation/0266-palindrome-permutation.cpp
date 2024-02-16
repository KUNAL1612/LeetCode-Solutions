class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> map(128, 0);
        int count = 0;
        for (char c : s) {
            map[c]++;
            if (map[c] % 2 == 0)
                count--;
            else
                count++;
        }
        return count <= 1;
    }
};