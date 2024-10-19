
---

# Algorithms Implementation

This repository contains implementations of various search algorithms, including British Museum Search, Breadth-First Search (BFS), Branch and Bound, Depth-First Search (DFS), Hill Climbing, Oracle Algorithm, Best-First Search, Beam Search, Extended Branch and Bound, Cost-Extended Branch and Bound, A* Algorithm, and AO* Algorithm. Below are sample inputs and outputs for each algorithm.

## Algorithms Overview

### 1. British Museum Search
**Sample Input:**
```
Number of nodes: 5
Goal node: 3
```

**Output:**
```
Visiting node: 0
Visiting node: 1
Visiting node: 2
Visiting node: 3
Goal found at node: 3
```

### 2. Breadth-First Search (BFS)
**Sample Input:**
```
Number of nodes: 5
Number of edges: 6
0 1
0 2
1 3
1 4
2 4
3 4
```

**Output:**
```
0 1 2 3 4
```

### 3. Branch and Bound
**Sample Input:**
```
Number of nodes: 4
Number of edges: 5
0 1 1
0 2 3
1 2 1
1 3 5
2 3 2
```

**Output:**
```
=== Branch and Bound ===
Minimum Cost: 4
Optimal Path: 0 -> 1 -> 2 -> 3
```

### 4. Depth-First Search (DFS)
**Sample Input:**
```
Number of nodes: 5
Number of edges: 5
0 1
0 2
1 3
1 4
2 4
```

**Output:**
```
DFS starting from node 0: 0 1 3 4 2
```

### 5. Hill Climbing
**Sample Input:**
```
Number of nodes: 5
Goal node: 3
Graph:
0: 1, 2
1: 0, 3
2: 0
3: 1
4: 
```

**Output:**
```
Starting hill climbing at node: 0
Moving to node: 1
Moving to node: 3
Goal found at node: 3
```

### 6. Oracle Algorithm
**Sample Input:**
```
Number of nodes: 5
Number of edges: 4
0 1
1 2
2 3
3 4
```

**Output:**
```
=== Oracle Algorithm ===
Simulating optimal solution for 5 nodes.
Optimal Path: 0 -> 1 -> 2 -> 3 -> 4
```

### 7. Best-First Search
**Sample Input:**
```
Number of nodes: 5
Number of edges: 6
0 1 1
0 2 4
1 3 2
1 4 7
2 4 3
3 4 1
Start node: 0
Goal node: 4
```

**Output:**
```
=== Best-First Search ===
Optimal Path: 0 <- 1 <- 4
```

### 8. Beam Search
**Sample Input:**
```
Number of nodes: 5
Goal node: 4
Graph:
0: 1, 2
1: 3, 4
2: 4
3: 
4: 
Beam Width: 2
```

**Output:**
```
Visiting node: 0
Visiting node: 1
Visiting node: 4
Goal found at node: 4
```

### 9. Extended Branch and Bound
**Sample Input:**
```
Number of nodes: 4
Number of edges: 5
0 1 1
0 2 3
1 2 1
1 3 5
2 3 2
Max nodes: 3
```

**Output:**
```
=== BB Extended ===
Minimum Cost: 4
Optimal Path: 0 -> 1 -> 2 -> 3
```

### 10. Cost-Extended Branch and Bound
**Sample Input:**
```
Number of nodes: 4
Number of edges: 5
0 1 1
0 2 3
1 2 1
1 3 5
2 3 2
```

**Output:**
```
=== BB + Cost + Extended ===
Minimum Cost: 4
Optimal Path: 0 -> 1 -> 2 -> 3
```

### 11. A* Algorithm
**Sample Input:**
```
Number of nodes: 5
Number of edges: 6
0 1 1
0 2 4
1 3 2
1 4 7
2 4 3
3 4 1
Start node: 0
Goal node: 4
```

**Output:**
```
A* solution: 4
```

### 12. AO* Algorithm
**Sample Input:**
```
Number of nodes: 5
Number of edges: 6
0 1 1
0 2 4
1 3 2
1 4 7
2 4 3
3 4 1
Start node: 0
Goal node: 4
```

**Output:**
```
=== AO* Algorithm ===
Optimal Path: 0 <- 1 <- 4
Total Cost: 4
```

## Conclusion

Feel free to explore the implementations, modify them, and use the sample inputs to test their functionalities. Each algorithm has its own strengths and weaknesses, and understanding them is crucial for solving various computational problems.

---

