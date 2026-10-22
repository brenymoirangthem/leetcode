class Solution {
public:
       vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        // Already connected: adding this edge creates a cycle
        if (rootX == rootY) {
            return false;
        }

        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
           int n = edges.size();

        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (!unite(u, v)) {
                return {u, v};
            }
        }

        return {};
    }
};