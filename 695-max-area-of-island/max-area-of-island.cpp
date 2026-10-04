class Solution {
public:

    int dfs(vector<vector<int>>& grid, int row, int col) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols) {
            return 0;
        }

        // Water or already visited
        if (grid[row][col] == 0) {
            return 0;
        }

        // Mark as visited
        grid[row][col] = 0;

        // Count current cell
        int area = 1;

        // Explore all 4 directions
        area += dfs(grid, row - 1, col); // Up
        area += dfs(grid, row + 1, col); // Down
        area += dfs(grid, row, col - 1); // Left
        area += dfs(grid, row, col + 1); // Right

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        for (int row = 0; row < rows; row++) {

            for (int col = 0; col < cols; col++) {

                if (grid[row][col] == 1) {

                    int area = dfs(grid, row, col);

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};