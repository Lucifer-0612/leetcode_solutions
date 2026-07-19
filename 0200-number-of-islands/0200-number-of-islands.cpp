class Solution {
public:
    int drow[4] = {-1, 1, 0, 0};
    int dcol[4] = {0, 0, -1, 1};

    void dfs(int row, int col, vector<vector<char>>& grid, int m, int n) {

        // Base Condition
        if (row < 0 || row >= m || col < 0 || col >= n ||
            grid[row][col] == '0') {
            return;
        }

        // Mark as visited
        grid[row][col] = '0';

        // Visit all 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            dfs(nr, nc, grid, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    islands++;
                    dfs(i, j, grid, m, n);
                }
            }
        }

        return islands;
    }
};