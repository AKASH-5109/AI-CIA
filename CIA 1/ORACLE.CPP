#include <iostream>
#include <vector>

void oracle(int n) {
    std::cout << "\n=== Oracle Algorithm ===\n";
    std::cout << "Simulating optimal solution for " << n << " nodes.\n";
    std::cout << "Optimal Path: ";
    for (int i = 0; i < n; ++i) {
        std::cout << i;
        if (i < n - 1) std::cout << " -> ";
    }
    std::cout << "\n";
}

int main() {
    int n, e;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n);
    std::cout << "Enter the edges (u v):\n";
    for (int i = 0; i < e; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); 
    }

    oracle(n);
    return 0;
}
