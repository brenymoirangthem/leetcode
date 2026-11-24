class Solution {
public:
    string rankTeams(vector<string>& votes) {
       int n = votes[0].size();

        vector<vector<int>> count(26, vector<int>(n, 0));

        // Count votes for every position
        for (string vote : votes) {
            for (int i = 0; i < n; i++) {
                count[vote[i] - 'A'][i]++;
            }
        }

        // Store all teams
        string teams = votes[0];

        // Sort teams according to their votes
        sort(teams.begin(), teams.end(), [&](char a, char b) {

            for (int i = 0; i < n; i++) {

                if (count[a - 'A'][i] != count[b - 'A'][i]) {
                    return count[a - 'A'][i] > count[b - 'A'][i];
                }
            }

            return a < b;
        });

        return teams;  
    }
};