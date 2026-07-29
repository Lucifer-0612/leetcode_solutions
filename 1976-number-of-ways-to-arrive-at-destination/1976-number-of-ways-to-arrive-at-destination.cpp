class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);

        // Build graph
        // adjency list
        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int wt = road[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        //min heap aise banta hai
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        //first 0 -> node , second 0 -> weight
        pq.push({0, 0});

        while (!pq.empty()) {

            auto [d, node] = pq.top(); //pop hota hai ise heap se
            pq.pop();

            // Ignore stale entries
            if (d > dist[node])
                continue;

            for (auto &[adjNode, wt] : adj[node]) {

                long long newDist = d + wt;

                // Better shortest path found
                if (newDist < dist[adjNode]) {

                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];

                    pq.push({newDist, adjNode});
                }

                // Another shortest path found
                else if (newDist == dist[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};