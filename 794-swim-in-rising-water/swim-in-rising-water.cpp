class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<bool>> visited(
            n, vector<bool>(n, false)
        );

        // {required time, row, column}
        pq.push({grid[0][0], 0, 0});

        int directions[5] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();

            int time = current[0];
            int row = current[1];
            int col = current[2];

            if (visited[row][col]) {
                continue;
            }

            visited[row][col] = true;

            if (row == n - 1 && col == n - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i];
                int nc = col + directions[i + 1];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    !visited[nr][nc]) {

                    int newTime = max(
                        time, grid[nr][nc]
                    );

                    pq.push({newTime, nr, nc});
                }
            }
        }

        return -1;
    }
};