#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int id, g, h;
    Node(int i, int g, int h) : id(i), g(g), h(h) {}

    int f() const { return g + h; }
    bool operator<(const Node& other) const { return f() > other.f(); }
};

int heuristic(int node) {
    return 0;
}

int aStar(int start, int goal, const std::vector<std::vector<std::pair<int, int>>>& graph) {
    std::priority_queue<Node> openList;
    openList.push(Node(start, 0, heuristic(start)));

    std::vector<bool> closedList(graph.size(), false);

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.id == goal) {
            return current.g;
        }

        closedList[current.id] = true;

        for (auto& neighbor : graph[current.id]) {
            int neighborId = neighbor.first;
            int edgeCost = neighbor.second;
            if (!closedList[neighborId]) {
                openList.push(Node(neighborId, current.g + edgeCost, heuristic(neighborId)));
            }
        }
    }

    return -1;
}

int main() {
    int n, e;
    std::cout << "Enter number of nodes and edges: ";
    std::cin >> n >> e;

    std::vector<std::vector<std::pair<int, int>>> graph(n);
    std::cout << "Enter edges (u v w) where there's an edge between u and v with weight w:\n";
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); 
    }

    int start, goal;
    std::cout << "Enter start and goal nodes: ";
    std::cin >> start >> goal;

    int solution = aStar(start, goal, graph);
    std::cout << "A* solution: " << solution << std::endl;
    return 0;
}