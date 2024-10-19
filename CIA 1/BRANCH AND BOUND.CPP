#include <iostream>
#include <vector>
#include <climits>

void branchAndBound(const std::vector<std::vector<int>>& graph, int start) {
    int n = graph.size();
    std::vector<bool> visited(n, false);
    int minCost = INT_MAX;
    std::vector<int> optimalPath;
    std::vector<int> currentPath;

    std::function<void(int, int, int)> bbHelper = [&](int node, int cost, int depth) {
        if (cost >= minCost) return; 

        currentPath.push_back(node);
        if (depth == n) { 
            if (cost < minCost) {
                minCost = cost;
                optimalPath = currentPath;
            }
        } else {
            visited[node] = true;
            for (int i = 0; i < n; ++i) {
                if (graph[node][i] != 0 && !visited[i]) {
                    bbHelper(i, cost + graph[node][i], depth + 1);
                }
            }
            visited[node] = false;
        }
        currentPath.pop_back();
    };

    bbHelper(start, 0, 1);

    std::cout << "\n=== Branch and Bound ===\n";
    std::cout << "Minimum Cost: " << minCost << "\nOptimal Path: ";
    for (int node : optimalPath) {
        std::cout << node;
        if (node != optimalPath.back()) std::cout << " -> ";
    }
    std::cout << "\n";
}

int main() {
    int n, e;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> e;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    std::cout << "Enter the edges (u v w) where w is the weight:\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }

    branchAndBound(graph, 0);
    return 0;
}
