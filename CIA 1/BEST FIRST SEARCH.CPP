#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Node {
    int id;
    std::vector<std::pair<int, int>> neighbors;

    bool operator>(const Node& other) const {
        return id > other.id;
    }
};

void bestFirstSearch(const std::vector<Node>& nodes, int start, int goal) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::vector<bool> visited(nodes.size(), false);
    std::vector<int> parent(nodes.size(), -1);
    pq.push(start);
    visited[start] = true;

    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();

        if (current == goal) {
            break; 
        }

        for (const auto& neighbor : nodes[current].neighbors) {
            int nextId = neighbor.first;
            if (!visited[nextId]) {
                visited[nextId] = true;
                parent[nextId] = current;
                pq.push(nextId);
            }
        }
    }

    std::cout << "\n=== Best-First Search ===\n";
    std::cout << "Optimal Path: ";
    for (int i = goal; i != -1; i = parent[i]) {
        std::cout << i;
        if (parent[i] != -1) std::cout << " <- ";
    }
    std::cout << "\n";
}

int main() {
    int n, e;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> e;

    std::vector<Node> nodes(n);
    std::cout << "Enter the edges (u v w) where w is the weight:\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        nodes[u].neighbors.emplace_back(v, w);
        nodes[v].neighbors.emplace_back(u, w); 
    }

    int start, goal;
    std::cout << "Enter start node and goal node: ";
    std::cin >> start >> goal;

    bestFirstSearch(nodes, start, goal);
    return 0;
}
