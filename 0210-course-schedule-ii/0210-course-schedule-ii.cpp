class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int& v = numCourses; // alias

        vector<int> adj[v], result(v), indegree(v);
        int topoLen = 0;

        // building adjacency list
        for (auto& pr : prerequisites) {
            adj[pr[1]].emplace_back(pr[0]);
        }

        for (int node = 0; node < v; node++) {
            for (auto& adjNode : adj[node])
                indegree[adjNode]++;
        }

        queue<int> Q;

        for (int node = 0; node < v; node++) {
            if (indegree[node] == 0)
                Q.emplace(node);
        }

        int i = 0;
        while (!Q.empty()) {
            int node = Q.front(); Q.pop();
            result[i++] = node;
            topoLen++;

            for (auto& adjNode : adj[node]) {
                if (--indegree[adjNode] == 0)
                    Q.emplace(adjNode);
            }
        }

        if (topoLen != v) return {};
        return result;
    }
};