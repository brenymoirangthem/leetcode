class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
           int n = words.size();

        // Calculate overlaps
        vector<vector<int>> overlap(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                int limit = min(words[i].size(), words[j].size());

                for (int k = limit; k >= 1; k--) {

                    if (words[i].substr(words[i].size() - k)
                        == words[j].substr(0, k)) {

                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        int total = 1 << n;

        vector<vector<int>> dp(total, vector<int>(n, -1));
        vector<vector<int>> parent(total, vector<int>(n, -1));

        // Initialize
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
        }

        // Bitmask DP
        for (int mask = 1; mask < total; mask++) {

            for (int i = 0; i < n; i++) {

                if (!(mask & (1 << i))) continue;
                if (dp[mask][i] == -1) continue;

                for (int j = 0; j < n; j++) {

                    if (mask & (1 << j)) continue;

                    int newMask = mask | (1 << j);

                    int newValue = dp[mask][i] + overlap[i][j];

                    if (newValue > dp[newMask][j]) {

                        dp[newMask][j] = newValue;
                        parent[newMask][j] = i;
                    }
                }
            }
        }

        // Find best ending word
        int mask = total - 1;
        int last = 0;

        for (int i = 1; i < n; i++) {
            if (dp[mask][i] > dp[mask][last]) {
                last = i;
            }
        }

        // Reconstruct order
        vector<int> order;

        while (last != -1) {

            order.push_back(last);

            int previous = parent[mask][last];

            mask ^= (1 << last);
            last = previous;
        }

        reverse(order.begin(), order.end());

        // Build answer
        string ans = words[order[0]];

        for (int i = 1; i < order.size(); i++) {

            int previous = order[i - 1];
            int current = order[i];

            ans += words[current].substr(overlap[previous][current]);
        }
//Google
        return ans;
    }
};