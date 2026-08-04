class Solution {
public:
    unordered_map<int, int> dp;

    int solve(int i, int n) {

        if (i == n)
            return 1;

        if (i > n)
            return 0;

        if (dp.find(i) != dp.end())
            return dp[i];

        int oneStep = solve(i + 1, n);
        int twoStep = solve(i + 2, n);

        return dp[i] = oneStep + twoStep;
    }

    int climbStairs(int n) {
        return solve(0, n);
    }
};