class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});
        }

        // Shortest distance to each node
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min-heap: {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated distances
            if (d > dist[node]) {
                continue;
            }

            // Explore neighboring nodes
            for (auto edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;

                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;

                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        int answer = 0;

        // Find the maximum shortest distance
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }

            answer = max(answer, dist[i]);
        }

        return answer;
    
    }
};