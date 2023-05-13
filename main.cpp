#include <iostream>
#include <vector>
#include <list>
#include <bitset>

const long long INF = INT32_MAX;

void dfs(long long node, const std::vector<std::list<long long>>& graph, std::bitset<100000>& visited) {
    visited.set(node);
    for (long long neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    long long T, n_cities, n_roads, cost_library, cost_road;
    std::cin >> T;
    while (std::cin >> n_cities >> n_roads >> cost_library >> cost_road) {
        std::vector<std::list<long long>> graph(n_cities, std::list<long long>());
        for (long long i = 0; i < n_roads; i++) {
            long long origin, destination;
            std::cin >> origin >> destination;
            graph[origin - 1].push_back(destination - 1);
            graph[destination - 1].push_back(origin - 1);
        }
        std::bitset<100000> visited;
        long long build_libraries = 0;
        for (long long i = 0; i < n_cities; ++i) {
            if (!visited[i]) {
                dfs(i, graph, visited);
                build_libraries++;
            }
        }

        if (cost_library < cost_road) {
            std::cout << cost_library * n_cities << std::endl;
        } else {
            std::cout << cost_library * build_libraries + cost_road * (n_cities - build_libraries) << std::endl;
        }
    }
    return 0;
}