#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int V = 5;

    vector<vector<pair<int, int>>> adj(V);

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<bool> visited(V, false);

    pq.push({0, 0});

    int mstWeight = 0;

    cout << "Edges in MST:\n";

    while (!pq.empty()) {

        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;

        mstWeight += wt;

        cout << node << " " << wt << endl;

        for (auto neighbour : adj[node]) {

            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    cout << "Total Weight = " << mstWeight << endl;

    return 0;
}