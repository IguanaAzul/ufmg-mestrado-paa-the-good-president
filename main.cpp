#include <iostream>
#include <vector>

using namespace std;
const int INF = INT32_MAX;

// Depth-First Search (DFS) algorithm
int dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    int edgeCount = 0;
    for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[node][neighbor] != INF && !visited[neighbor]) {
            visited[neighbor] = true;  // Mark the neighbor as visited immediately to avoid revisiting
            edgeCount++;  // Increment edge count for each visited edge
            edgeCount += dfs(neighbor, graph, visited);
        }
    }
    return edgeCount;
}

int main() {
    int T, n_cities, n_roads, cost_library, cost_road;
    cin >> T;
    while (cin >> n_cities >> n_roads >> cost_library >> cost_road) {
        vector<vector<int>> graph_matrix(n_cities, vector<int>(n_cities, INF));
        for (int i = 0; i < n_roads; i++) {
            int origin, destination;
            cin >> origin >> destination;
            graph_matrix[origin - 1][destination - 1] = cost_road;
            graph_matrix[destination - 1][origin - 1] = cost_road;
        }
        vector<bool> visited(n_cities, false);
        int build_roads = 0, build_libraries = 0;
        for (int i = 0; i < n_cities; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                build_roads += dfs(i, graph_matrix, visited);
                build_libraries++;
            }
        }
        cout << cost_library * build_libraries + cost_road * build_roads << endl;
    }
    return 0;
}