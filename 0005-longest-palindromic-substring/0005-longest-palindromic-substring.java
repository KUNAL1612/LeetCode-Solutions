class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        // int n = s.size();
        boolean[][] dp = new boolean[n][n];
        // vector<vector<bool>> dp(n, vector<bool> (n,0));
        int[] ans = new int[]{0, 0};
        
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true; // single emenent
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                ans[0] = i;
                ans[1] = i + 1;
            }
        }
        
        for (int diff = 2; diff < n; diff++) { 
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        
        int i = ans[0]; // indices of the longest substring palindromic
        int j = ans[1];
        return s.substring(i, j + 1);
    }
}

// class Solution {
//     public String longestPalindrome(String s) {
//     if (s == null || s.length() < 1) return "";
//     int start = 0, end = 0;
//     for (int i = 0; i < s.length(); i++) {
//         int len1 = expandAroundCenter(s, i, i);
//         int len2 = expandAroundCenter(s, i, i + 1);
//         int len = Math.max(len1, len2);
//         if (len > end - start) {
//             start = i - (len - 1) / 2;
//             end = i + len / 2;
//         }
//     }
//     return s.substring(start, end + 1);
// }

// private int expandAroundCenter(String s, int left, int right) {
//     int L = left, R = right;
//     while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
//         L--;
//         R++;
//     }
//     return R - L - 1;
// }
// }