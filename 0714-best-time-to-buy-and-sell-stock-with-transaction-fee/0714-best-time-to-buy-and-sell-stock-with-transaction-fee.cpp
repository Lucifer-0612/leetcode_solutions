class Solution {
public:

    int solution(vector<int>& prices, int n, int i, int buy,
                 int fee, vector<vector<int>>& dp)
    {
        if (i >= n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy)
        {
            // Buy
            int c1 = solution(prices, n, i + 1, 0, fee, dp)
                     - prices[i];

            // Skip
            int c2 = solution(prices, n, i + 1, 1, fee, dp);

            return dp[i][buy] = max(c1, c2);
        }
        else
        {
            // Sell + pay transaction fee
            int c1 = solution(prices, n, i + 1, 1, fee, dp)
                     + prices[i] - fee;

            // Skip
            int c2 = solution(prices, n, i + 1, 0, fee, dp);

            return dp[i][buy] = max(c1, c2);
        }
    }

    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solution(prices, n, 0, 1, fee, dp);
    }
};