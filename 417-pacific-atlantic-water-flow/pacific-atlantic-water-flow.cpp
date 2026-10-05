class Solution {
public:

    int rows;
    int cols;

    void dfs(vector<vector<int>>& heights,
             int row,
             int col,
             vector<vector<bool>>& visited,
             int previousHeight) {

        // Out of bounds
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols) {
            return;
        }

        // Already visited
        if (visited[row][col]) {
            return;
        }

        // Water cannot flow from low to high in the original direction.
        // We are doing reverse DFS, so the next cell must be
        // at least as high as the current cell.
        if (heights[row][col] < previousHeight) {
            return;
        }

        // Mark current cell as reachable
        visited[row][col] = true;

        // Up
        dfs(heights, row - 1, col,
            visited, heights[row][col]);

        // Down
        dfs(heights, row + 1, col,
            visited, heights[row][col]);

        // Left
        dfs(heights, row, col - 1,
            visited, heights[row][col]);

        // Right
        dfs(heights, row, col + 1,
            visited, heights[row][col]);
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );

        // Pacific: top row
        for (int col = 0; col < cols; col++) {
            dfs(heights, 0, col,
                pacific, heights[0][col]);
        }

        // Pacific: left column
        for (int row = 0; row < rows; row++) {
            dfs(heights, row, 0,
                pacific, heights[row][0]);
        }

        // Atlantic: bottom row
        for (int col = 0; col < cols; col++) {
            dfs(heights, rows - 1, col,
                atlantic, heights[rows - 1][col]);
        }

        // Atlantic: right column
        for (int row = 0; row < rows; row++) {
            dfs(heights, row, cols - 1,
                atlantic, heights[row][cols - 1]);
        }

        vector<vector<int>> answer;

        // Find cells reachable from BOTH oceans
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (pacific[row][col] &&
                    atlantic[row][col]) {

                    answer.push_back({row, col});
                }
            }
        }

        return answer;
    }
};