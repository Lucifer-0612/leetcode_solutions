class Solution {
public:
        int solution(vector<int>& prices, int n, int i, int k,
                 vector<vector<int>>& dp)
    {
        if (i == n)
            return 0;

        if (k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        if (k % 2 == 0)
        {
            // Buy
            int c1 = solution(prices, n, i + 1, k - 1, dp) - prices[i];

            // Skip
            int c2 = solution(prices, n, i + 1, k, dp);

            return dp[i][k] = max(c1, c2);
        }
        else
        {
            // Sell
            int c1 = solution(prices, n, i + 1, k - 1, dp) + prices[i];

            // Skip
            int c2 = solution(prices, n, i + 1, k, dp);

            return dp[i][k] = max(c1, c2);
        }
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         k = k*2;

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        int gain = solution(prices, n, 0, k, dp);

        return gain;
    }
};