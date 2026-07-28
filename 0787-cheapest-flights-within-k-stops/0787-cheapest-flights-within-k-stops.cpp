class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Run Bellman-Ford for K+1 iterations
        for (int i = 0; i < k + 1; i++) {

            vector<int> temp = dist; // har iteration ko temparory store karne ke leye

            for (auto &flight : flights) {

                int u = flight[0];
                int v = flight[1];
                int wt = flight[2];

                if (dist[u] != INT_MAX &&
                    dist[u] + wt < temp[v]) {

                    temp[v] = dist[u] + wt;
                }
            }

            dist = temp;
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};