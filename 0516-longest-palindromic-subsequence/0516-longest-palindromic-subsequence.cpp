class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
      
        // dp[i][j] represents the length of longest palindromic subsequence
        // in substring s[i...j]
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
      
        // Base case: single character is always a palindrome of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
      
        // Fill the dp table bottom-up
        // Start from the end of string and move backwards
        for (int i = n - 1; i >= 0; --i) {
            // For each starting position i, check all ending positions j after i
            for (int j = i + 1; j < n; ++j) {
                // If characters at both ends match, add 2 to the result of inner substring
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    // If characters don't match, take maximum of:
                    // 1. Excluding character at position i
                    // 2. Excluding character at position j
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
      
        // Return the longest palindromic subsequence for entire string
        return dp[0][n - 1];
    }
};
