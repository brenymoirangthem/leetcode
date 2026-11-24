class Solution {
public:
     int n;
    queue<pair<int, int>> q;
    int dir[5] = {0, 1, 0, -1, 0};

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= n || c >= n ||
            grid[r][c] != 1) {
            return;
        }

        grid[r][c] = 2;
        q.push({r, c});

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];

            dfs(grid, nr, nc);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();

        // Step 1: Find and mark the first island
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    found = true;
                }
            }
        }

        // Step 2: BFS from the first island
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + dir[i];
                    int nc = c + dir[i + 1];

                    if (nr < 0 || nc < 0 ||
                        nr >= n || nc >= n) {
                        continue;
                    }

                    if (grid[nr][nc] == 1) {
                        return steps;
                    }

                    if (grid[nr][nc] == 0) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }

            steps++;
        }

        return -1;
      
    }
};