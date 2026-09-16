class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> columns(9);
        vector<unordered_set<char>> boxes(9);

        for(int row = 0;row<9;row++){
            for(int column = 0;column<9;column++){
                char num = board[row][column];
                if( num == '.'){
                    continue;
                }
                int box = (row/3)*3 + (column/3);
                if(rows[row].count(num)||columns[column].count(num)||boxes[box].count(num)){
                    return false;
                }
                rows[row].insert(num);
                columns[column].insert(num);
                boxes[box].insert(num);                
            }
        }
    return true;    
    }
};