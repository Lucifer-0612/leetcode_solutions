class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int row, int c1, int c2, vector<vector<int>>& grid) {
        
        // Out of bounds
        if (c1 < 0 || c1 >= m || c2 < 0 || c2 >= m)
            return -1e9;

        // Last row
        if (row == n - 1) {
            if (c1 == c2)
                return grid[row][c1];

            return grid[row][c1] + grid[row][c2];
        }

        // Already calculated
        if (dp[row][c1][c2] != -1)
            return dp[row][c1][c2];

        // Current cherries
        int cherries = grid[row][c1];

        if (c1 != c2)
            cherries += grid[row][c2];

        int best = -1e9;

        // 3 choices for Robot 1 × 3 choices for Robot 2
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {

                best = max(
                    best,
                    solve(row + 1,
                          c1 + d1,
                          c2 + d2,
                          grid)
                );
            }
        }

        return dp[row][c1][c2] = cherries + best;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(
            n,
            vector<vector<int>>(
                m,
                vector<int>(m, -1)
            )
        );

        // Robot 1 -> (0,0)
        // Robot 2 -> (0,m-1)
        return solve(0, 0, m - 1, grid);
    }
};