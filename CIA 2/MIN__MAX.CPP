#include <iostream>
#include <vector>
#include <algorithm>

int minimax(int node, bool isMax, const std::vector<std::vector<int>>& graph, const std::vector<int>& values, std::vector<bool>& visited) {
    visited[node] = true;
    if (graph[node].empty()) {
        return values[node]; 
    }

    if (isMax) {
        int best = -1000;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                best = std::max(best, minimax(neighbor, false, graph, values, visited));
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                best = std::min(best, minimax(neighbor, true, graph, values, visited));
            }
        }
        return best;
    }
}

int main() {
    int n, e;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> values(n);
    std::vector<bool> visited(n, false);
    
    std::cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  
    }

    std::cout << "Enter values for each node: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }

    std::cout << "Optimal value starting from node 0: ";
    std::cout << minimax(0, true, graph, values, visited) << std::endl;
    return 0;
}