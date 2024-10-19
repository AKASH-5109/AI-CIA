#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int id;
    int heuristic;

    bool operator<(const Node &other) const {
        return heuristic > other.heuristic; // Min-heap based on heuristic
    }
};

void beamSearch(const std::vector<std::vector<int>> &graph, int start, int goal, int beamWidth) {
    std::priority_queue<Node> pq;
    pq.push({start, heuristic(start, goal)});

    while (!pq.empty()) {
        std::priority_queue<Node> nextQueue;

        for (int i = 0; i < beamWidth && !pq.empty(); i++) {
            Node current = pq.top();
            pq.pop();
            std::cout << "Visiting node: " << current.id << std::endl;

            if (current.id == goal) {
                std::cout << "Goal found at node: " << goal << std::endl;
                return;
            }

            for (int neighbor : graph[current.id]) {
                nextQueue.push({neighbor, heuristic(neighbor, goal)});
            }
        }
        pq = nextQueue;
    }
}