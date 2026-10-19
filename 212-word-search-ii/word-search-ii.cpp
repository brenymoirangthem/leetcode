class Solution {
public:
  struct Node {
        Node* links[26];
        string word;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            word = "";
        }
    };

    Node* root;

    Solution() {
        root = new Node();
    }

    void insert(string w) {
        Node* node = root;

        for (char ch : w) {
            int index = ch - 'a';

            if (node->links[index] == nullptr) {
                node->links[index] = new Node();
            }

            node = node->links[index];
        }

        node->word = w;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             Node* node, vector<string>& ans) {

        char ch = board[r][c];
        int index = ch - 'a';

        if (node->links[index] == nullptr) {
            return;
        }

        node = node->links[index];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if (r > 0 && board[r - 1][c] != '#')
            dfs(board, r - 1, c, node, ans);

        if (r + 1 < rows && board[r + 1][c] != '#')
            dfs(board, r + 1, c, node, ans);

        if (c > 0 && board[r][c - 1] != '#')
            dfs(board, r, c - 1, node, ans);

        if (c + 1 < cols && board[r][c + 1] != '#')
            dfs(board, r, c + 1, node, ans);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        root = new Node();

        for (string w : words) {
            insert(w);
        }

        vector<string> ans;

        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root, ans);
            }
        }

        return ans;
    }
};
