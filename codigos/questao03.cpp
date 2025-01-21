#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int kruskal(int m, int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DisjointSet ds(m);
    int totalCost = 0, mstCost = 0;
    
    for (const auto& edge : edges)
        totalCost += edge.weight;
    
    for (const auto& edge : edges) {
        if (ds.find(edge.u) != ds.find(edge.v)) {
            ds.unite(edge.u, edge.v);
            mstCost += edge.weight;
        }
    }
    return totalCost - mstCost;
}

int main() {
    int m, n;
    while (cin >> m >> n, m || n) {
        vector<Edge> edges(n);
        for (int i = 0; i < n; i++)
            cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        cout << kruskal(m, n, edges) << "\n";
    }
    return 0;
}
