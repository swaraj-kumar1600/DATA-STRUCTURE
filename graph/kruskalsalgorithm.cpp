#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

int main() {

    int V = 4;

    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    sort(edges.begin(), edges.end(),
        [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

    DisjointSet ds(V);

    int mstWeight = 0;

    cout << "Edges in MST:\n";

    for (auto edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if (ds.findParent(u) != ds.findParent(v)) {

            cout << u << " - " << v << " : " << wt << endl;

            mstWeight += wt;

            ds.unionByRank(u, v);
        }
    }

    cout << "Total Weight = " << mstWeight << endl;

    return 0;
}