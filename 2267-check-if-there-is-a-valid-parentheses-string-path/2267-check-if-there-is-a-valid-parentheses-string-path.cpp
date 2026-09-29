class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {

        // Out of bounds
        if (i >= m || j >= n)
            return false;

        // Update balance
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid balance
        if (balance < 0)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Already calculated
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move down / right
        bool down = solve(i + 1, j, balance, grid);
        bool right = solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 == 1)
            return false;

        // Starting cell must be '('
        if (grid[0][0] == ')')
            return false;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n, -1)
            )
        );

        return solve(0, 0, 0, grid);
    }
};