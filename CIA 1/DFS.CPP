#include <iostream>
#include <vector>

void dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n, e; 
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n);
    std::cout << "Enter edges (u v) where there's an edge between u and v:\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    std::vector<bool> visited(n, false);
    std::cout << "DFS starting from node 0: ";
    dfs(0, graph, visited);
    return 0;
}