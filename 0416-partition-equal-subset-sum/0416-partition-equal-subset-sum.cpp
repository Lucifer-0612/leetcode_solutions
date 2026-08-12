class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i];

        // Equal partition is possible only if total sum is even
        if(sum % 2 != 0)
            return false;

        sum = sum / 2;

        int i, j;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        // Base case
        for(j = 0; j <= sum; j++)
        {
            dp[n][j] = 0;
        }

        dp[n][0] = 1;

        // Bottom-up DP
        for(i = n - 1; i >= 0; i--)
        {
            for(j = 0; j <= sum; j++)
            {
                if(nums[i] > j)
                    dp[i][j] = dp[i + 1][j];

                else
                    dp[i][j] = dp[i + 1][j - nums[i]] ||
                               dp[i + 1][j];
            }
        }

        return dp[0][sum];
    }
};