class Solution { 
public: 
    void dfs(vector<vector<char>>& board, int row, int col) { 
        int rows = board.size(); 
        int cols = board[0].size(); 
 
        if (row < 0 || row >= rows || 
            col < 0 || col >= cols) { 
            return; 
        } 
 
        if (board[row][col] != 'O') { 
            return; 
        } 
 
        board[row][col] = 'T'; 
 
        dfs(board, row - 1, col); 
        dfs(board, row + 1, col); 
        dfs(board, row, col - 1); 
        dfs(board, row, col + 1); 
    }

    void solve(vector<vector<char>>& board) { 
        int rows = board.size(); 
        int cols = board[0].size(); 
 
        // Top and bottom rows 
        for (int col = 0; col < cols; col++) { 
            if (board[0][col] == 'O') { 
                dfs(board, 0, col); 
            } 
 
            if (board[rows - 1][col] == 'O') { 
                dfs(board, rows - 1, col); 
            } 
        } 
 
        // Left and right columns 
        for (int row = 0; row < rows; row++) { 
            if (board[row][0] == 'O') { 
                dfs(board, row, 0); 
            } 
      
            if (board[row][cols - 1] == 'O') { 
                dfs(board, row, cols - 1); 
            } 
        }

        // Convert surrounded O to X
        // Convert safe T back to O
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == 'T') {
                    board[row][col] = 'O';
                }
            }
        }
    } 
};