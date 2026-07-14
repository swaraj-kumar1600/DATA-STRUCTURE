#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        auto [distance, node] = pq.top();
        pq.pop();

        for (auto [adjNode, edgeWeight] : adj[node]) {

            if (distance + edgeWeight < dist[adjNode]) {

                dist[adjNode] = distance + edgeWeight;

                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 1});
    adj[3].push_back({0, 1});

    adj[1].push_back({2, 4});
    adj[2].push_back({1, 4});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[3].push_back({2, 3});
    adj[2].push_back({3, 3});

    adj[2].push_back({4, 1});
    adj[4].push_back({2, 1});

    int source = 0;

    vector<int> dist = dijkstra(V, adj, source);

    cout << "Shortest Distance from Source " << source << ":\n";

    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}