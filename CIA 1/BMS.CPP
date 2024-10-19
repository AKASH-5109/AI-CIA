#include <iostream>
#include <vector>
#include <cstdlib>

void britishMuseumSearch(const std::vector<std::vector<int>> &graph, int goal) {
    int randomNode;
    while (true) {
        randomNode = rand() % graph.size();
        std::cout << "Visiting node: " << randomNode << std::endl;
        if (randomNode == goal) {
            std::cout << "Goal found at node: " << goal << std::endl;
            break;
        }
    }
}