/*Graphs are crucial for solving connectivity, pathfinding, and network-related problems.

Code: Depth-First Search (DFS)*/


#include <vector>
#include <iostream>
using namespace std;

// Function to perform DFS
void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << "Visited: " << node << endl;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to 1, 2
        {0, 3},     // Node 1 is connected to 0, 3
        {0, 4},     // Node 2 is connected to 0, 4
        {1},        // Node 3 is connected to 1
        {2}         // Node 4 is connected to 2
    };

    vector<bool> visited(graph.size(), false);
    dfs(0, graph, visited);

    return 0;
}
//Problems like Number of Connected Components.
//Maze traversal or cycle detection.