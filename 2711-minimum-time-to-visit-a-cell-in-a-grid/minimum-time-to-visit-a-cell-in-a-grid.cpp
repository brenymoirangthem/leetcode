class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
       int m = grid.size();
        int n = grid[0].size();

        // Check if we can make our first move
        if (m > 1 && n > 1 &&
            grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        if (m == 1 && n > 1 && grid[0][1] > 1) {
            return -1;
        }

        if (n == 1 && m > 1 && grid[1][0] > 1) {
            return -1;
        }

        vector<vector<int>> dist(m, vector<int>(n, 1e9));

        // Min heap: {time, row, col}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (time > dist[r][c]) {
                continue;
            }

            if (r == m - 1 && c == n - 1) {
                return time;
            }

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Check boundaries
                if (nr < 0 || nr >= m ||
                    nc < 0 || nc >= n) {
                    continue;
                }

                int nextTime = time + 1;

                // Adjust time if the cell is not yet accessible
                if (nextTime < grid[nr][nc]) {
                    nextTime = grid[nr][nc] +
                               (grid[nr][nc] - nextTime) % 2;
                }

                if (nextTime < dist[nr][nc]) {

                    dist[nr][nc] = nextTime;

                    pq.push({nextTime, nr, nc});
                }
            }
        }

        return -1; 
    }
};