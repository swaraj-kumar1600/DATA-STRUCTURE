#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kahnsAlgorithm(int V, vector<vector<int>>& adj) {

    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int neighbour : adj[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        topoOrder.push_back(node);

        for (int neighbour : adj[node]) {

            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return topoOrder;
}

int main() {

    int V = 6;

    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> ans = kahnsAlgorithm(V, adj);

    cout << "Topological Order:\n";

    for (int node : ans) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}