class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
           vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build the graph
        for (const auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Add courses with indegree 0
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        // Kahn's Algorithm (BFS)
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            completed++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return completed == numCourses;
    }
};