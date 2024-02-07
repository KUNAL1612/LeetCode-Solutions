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