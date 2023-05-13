#include <iostream>
#include <vector>

using namespace std;
const int INF = INT32_MAX;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[node][neighbor] != INF && !visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int T, n_cities, n_roads, cost_library, cost_road;
    cin >> T;
    while (cin >> n_cities >> n_roads >> cost_library >> cost_road) {
        vector<vector<int>> graph_matrix(n_cities, vector<int>(n_cities, INF));
        for (int i = 0; i < n_roads; i++) {
            int origin, destination;
            cin >> origin >> destination;
            graph_matrix[origin - 1][destination - 1] = 1;
            graph_matrix[destination - 1][origin - 1] = 1;
        }
        vector<bool> visited(n_cities, false);
        int build_libraries = 0;
        for (int i = 0; i < n_cities; ++i) {
            if (!visited[i]) {
                dfs(i, graph_matrix, visited);
                build_libraries++;
            }
        }

        if (cost_library < cost_road) {
            cout << cost_library * n_cities << endl;
        } else {
            cout << cost_library * build_libraries + cost_road * (n_cities - build_libraries) << endl;
        }
    }
    return 0;
}