class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
          unordered_map<int, unordered_set<int>> mp;

        // Store unique active minutes for each user
        for (auto& log : logs) {
            int user = log[0];
            int time = log[1];

            mp[user].insert(time);
        }

        vector<int> ans(k, 0);

        // Count users according to their UAM
        for (auto& entry : mp) {

            int uam = entry.second.size();

            ans[uam - 1]++;
        }

        return ans;
    }
};