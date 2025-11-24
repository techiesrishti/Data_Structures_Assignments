# Assignment No: 8 (UNIT 5)  
# Title: Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.
# Same as Assignment No.: 2

## Concepts Used:
- Graph representation using adjacency list  
- Minimum Spanning Tree (MST)  
- Prim’s Algorithm using Priority Queue (Min-Heap)  
- STL containers: vector, priority_queue  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `n`  
Step 2: Initialize adjacency list `adj` as a vector of vectors of edges  
Step 3: Input number of edges `e`  
Step 4: For each edge, input `u`, `v`, and `weight`  
        Step 4.1: Add edge to adjacency list for both `u` and `v` (undirected)  

### 2. Display Adjacency List
Step 1: For each vertex `i` from 0 to `n-1`:  
        Step 1.1: Print `i ->`  
        Step 1.2: For each edge `(to, weight)` in `adj[i]`:  
                    Print `(to, weight)`  

### 3. Prim's Algorithm
Step 1: Initialize boolean array `visited` of size `n` to 0  
Step 2: Create a priority queue `pq` to store pairs `(weight, vertex)` in ascending order  
Step 3: Push `(0, start)` into `pq`  
Step 4: Initialize `totalCost` = 0  
Step 5: While `pq` is not empty:  
        Step 5.1: Pop top element `(wt, node)` from `pq`  
        Step 5.2: If `node` is already visited, continue  
        Step 5.3: Mark `node` as visited  
        Step 5.4: If `wt != 0`, print edge weight selected for MST  
        Step 5.5: Add `wt` to `totalCost`  
        Step 5.6: For each adjacent edge `(nextNode, nextWeight)` of `node`:  
                    If `nextNode` is not visited:  
                        Push `(nextWeight, nextNode)` into `pq`  
Step 6: Print `totalCost` as the Minimum Spanning Tree cost  

## Stepwise :
1. Input number of vertices `n`  
2. Input number of edges `e`  
3. Input all edges `(u, v, weight)`  
4. Build adjacency list  
5. Display adjacency list  
6. Input starting vertex for Prim's Algorithm  
7. Execute Prim's Algorithm:  
   - Select edges with minimum weight connecting unvisited vertices  
   - Add weights to `totalCost`  
   - Display edges selected for MST  
8. Display `totalCost`  

## Output:
Enter number of vertices: 5
Enter number of edges: 7
Enter edges as: u v weight
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

--- Graph Representation (Adjacency List) ---
0 -> (1, 2) (3, 6)
1 -> (0, 2) (2, 3) (3, 8) (4, 5)
2 -> (1, 3) (4, 7)
3 -> (0, 6) (1, 8) (4, 9)
4 -> (1, 5) (2, 7) (3, 9)

Enter starting vertex for Prim's Algorithm: 0

Edges selected for Minimum Spanning Tree:
Edge with weight: 2
Edge with weight: 3
Edge with weight: 5
Edge with weight: 6

Total Minimum Cost: 16

---
