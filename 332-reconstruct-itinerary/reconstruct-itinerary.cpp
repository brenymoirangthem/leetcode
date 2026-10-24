class Solution {
public:
    unordered_map<string, priority_queue<string,
        vector<string>, greater<string>>> adj;

    vector<string> itinerary;

    void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = adj[airport].top();
            adj[airport].pop();

            dfs(next);
        }

        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};