#include <iostream>
#include <vector>
#include <limits.h>

int alphaBeta(int node, bool isMax, const std::vector<std::vector<int>>& graph, const std::vector<int>& values, int alpha, int beta, std::vector<bool>& visited) {
    visited[node] = true;
    if (graph[node].empty()) {
        return values[node]; 
    }

    if (isMax) {
        int best = INT_MIN;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                best = std::max(best, alphaBeta(neighbor, false, graph, values, alpha, beta, visited));
                alpha = std::max(alpha, best);
                if (beta <= alpha)
                    break;
            }
        }
        return best;
    } else {
        int best = INT_MAX;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                best = std::min(best, alphaBeta(neighbor, true, graph, values, alpha, beta, visited));
                beta = std::min(beta, best);
                if (beta <= alpha)
                    break;
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

    std::cout << "Optimal value with Alpha-Beta Pruning starting from node 0: ";
    std::cout << alphaBeta
}