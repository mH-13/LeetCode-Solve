#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Function to find the shortest path using Dijkstra's algorithm
vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [currentDist, u] = pq.top();
        pq.pop();

        if (currentDist > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj = {
        {{1, 2}, {2, 4}},  // Node 0 -> Node 1 (2), Node 2 (4)
        {{2, 1}, {3, 7}},  // Node 1 -> Node 2 (1), Node 3 (7)
        {{4, 3}},          // Node 2 -> Node 4 (3)
        {{4, 1}},          // Node 3 -> Node 4 (1)
        {}                 // Node 4 has no outgoing edges
    };

    vector<int> distances = dijkstra(n, adj, 0);
    for (int i = 0; i < n; ++i) {
        cout << "Distance from 0 to " << i << ": " << distances[i] << endl;
    }

    return 0;
}


//Problems like Network Delay Time.
//Finding shortest paths in weighted graphs.
//