class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        // Special case: only one node
        if (n == 1) {
            return {0};
        }

        // Adjacency list
        vector<vector<int>> adj(n);

        // Degree of every node
        vector<int> degree(n, 0);

        // Build graph
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        // Store all leaf nodes
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remainingNodes = n;

        // Remove leaves layer by layer
        while (remainingNodes > 2) {

            int leafCount = q.size();

            remainingNodes -= leafCount;

            while (leafCount--) {

                int leaf = q.front();
                q.pop();

                // Remove this leaf from the graph
                for (int neighbor : adj[leaf]) {

                    degree[neighbor]--;

                    // New leaf formed
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Remaining nodes are the centers
        vector<int> result;

        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};