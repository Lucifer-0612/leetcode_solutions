class Solution {
public:
    int drow[4] = {-1, 1, 0, 0};
    int dcol[4] = {0, 0, -1, 1};

    void dfs(int row, int col, vector<vector<int>>& grid, int m, int n) {

        // Base Conditions
        if (row < 0 || row >= m || col < 0 || col >= n ||
            grid[row][col] == 0) {
            return;
        }

        // Mark as visited
        grid[row][col] = 0;

        // Visit all 4 neighbours
        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            dfs(nr, nc, grid, m, n);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Traverse Top & Bottom Boundary
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                dfs(0, j, grid, m, n);

            if (grid[m - 1][j] == 1)
                dfs(m - 1, j, grid, m, n);
        }

        // Traverse Left & Right Boundary
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                dfs(i, 0, grid, m, n);

            if (grid[i][n - 1] == 1)
                dfs(i, n - 1, grid, m, n);
        }

        // Count remaining land cells (Enclaves)
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};