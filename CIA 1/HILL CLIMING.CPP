#include <iostream>
#include <vector>

int heuristic(int node, int goal) {
    return abs(goal - node);
}

void hillClimbing(const std::vector<std::vector<int>> &graph, int start, int goal) {
    int current = start;
    std::cout << "Starting hill climbing at node: " << current << std::endl;

    while (current != goal) {
        int next = current;
        for (int neighbor : graph[current]) {
            if (heuristic(neighbor, goal) < heuristic(next, goal)) {
                next = neighbor;
            }
        }

        if (next == current) {
            std::cout << "Stuck at local maxima at node: " << current << std::endl;
            return;
        }
        current = next;
        std::cout << "Moving to node: " << current << std::endl;
    }
    std::cout << "Goal found at node: " << goal << std::endl;
}
