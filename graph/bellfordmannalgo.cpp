#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {

        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for (auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            cout << "Negative Weight Cycle Detected\n";
            return {};
        }
    }

    return dist;
}

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;

    vector<int> dist = bellmanFord(V, edges, source);

    if (!dist.empty()) {

        cout << "Shortest Distance from Source " << source << ":\n";

        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}