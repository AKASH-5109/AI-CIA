#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Node {
    int id;
    int cost;
    int heuristic;
    std::vector<std::pair<int, int>> neighbors;

    bool operator>(const Node& other) const {
        return (cost + heuristic) > (other.cost + other.heuristic);
    }
};

void aoStar(const std::vector<Node>& nodes, int start, int goal) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    std::vector<int> minCost(nodes.size(), std::numeric_limits<int>::max());
    std::vector<int> parent(nodes.size(), -1);

    pq.push(nodes[start]);
    minCost[start] = 0;

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.id == goal) {
            break;
        }

        for (const auto& neighbor : current.neighbors) {
            int nextId = neighbor.first;
            int edgeCost = neighbor.second;
            int newCost = current.cost + edgeCost;

            if (newCost < minCost[nextId]) {
                minCost[nextId] = newCost;
                parent[nextId] = current.id;
                Node nextNode = nodes[nextId];
                nextNode.cost = newCost; 
                pq.push(nextNode);
            }
        }
    }

    std::cout << "\n=== AO* Algorithm ===\n";
    std::cout << "Optimal Path: ";
    for (int i = goal; i != -1; i = parent[i]) {
        std::cout << i;
        if (parent[i] != -1) std::cout << " <- ";
    }
    std::cout << "\nTotal Cost: " << minCost[goal] << "\n";
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

    for (int i = 0; i < n; ++i) {
        nodes[i].id = i;
        nodes[i].cost = 0;
        nodes[i].heuristic = rand() % 10; 
    }

    int start, goal;
    std::cout << "Enter start node and goal node: ";
    std::cin >> start >> goal;

    aoStar(nodes, start, goal);
    return 0;
}
