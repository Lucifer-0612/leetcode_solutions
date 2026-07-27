class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int drow[4] = {-1, 1, 0, 0};
        int dcol[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto p = pq.top();
            pq.pop();

            int effort = p.first;
            int row = p.second.first;
            int col = p.second.second;

            // Destination reached
            if (row == m - 1 && col == n - 1)
                return effort;

            // Ignore stale entry
            if (effort > dist[row][col])
                continue;

            for (int i = 0; i < 4; i++) {

                int nr = row + drow[i];
                int nc = col + dcol[i];

                if (nr >= 0 && nr < m &&   //condition check
                    nc >= 0 && nc < n) {  

                    int wt = abs(heights[row][col] - heights[nr][nc]);

                    int newEffort = max(effort, wt);

                    if (newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};