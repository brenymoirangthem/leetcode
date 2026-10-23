class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
                int n = points.size();

        vector<bool> visited(n, false);

        // {cost, point index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, 0});

        int totalCost = 0;
        int connected = 0;

        while (connected < n) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (visited[node]) {
                continue;
            }

            visited[node] = true;
            totalCost += cost;
            connected++;

            for (int next = 0; next < n; next++) {
                if (!visited[next]) {
                    int distance =
                        abs(points[node][0] - points[next][0]) +
                        abs(points[node][1] - points[next][1]);

                    pq.push({distance, next});
                }
            }
        }

        return totalCost;

    }
};