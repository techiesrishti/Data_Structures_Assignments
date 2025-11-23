# Assignment No: 9 (UNIT 5)  
# Title: Write a Program to implement Kruskal’s algorithm to find the minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.

## Concepts Used:
- Graph representation using adjacency list and edge list  
- Kruskal's algorithm for MST  
- Disjoint Set Union (DSU) with path compression and union by rank  
- Sorting edges by weight  
- Greedy algorithm concept  
- STL containers: vector, pair  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Initialize adjacency list `adjList` of size V  
Step 3: Initialize edge list `edgeList`  
Step 4: Input number of edges `E`  
Step 5: For each edge, input `src`, `dest`, `weight`  
        Step 5.1: Add `(dest, weight)` to `adjList[src]`  
        Step 5.2: Add `(src, weight)` to `adjList[dest]` (undirected)  
        Step 5.3: Add edge to `edgeList`  

### 2. Display Adjacency List
Step 1: For each vertex `v` from 0 to V-1:  
        Step 1.1: Print `v -> `  
        Step 1.2: For each neighbor `(neighbor, weight)` in `adjList[v]`:  
                    Print `(neighbor, weight)`  

### 3. Kruskal's MST Algorithm
Step 1: Sort `edgeList` in ascending order of weight  
Step 2: Initialize `parent[V]` such that `parent[i] = i`  
Step 3: Initialize `rank[V] = 0`  
Step 4: Initialize empty `mst` and `totalWeight = 0`  
Step 5: For each edge `(u, v, w)` in `edgeList`:  
        Step 5.1: Find parents `p1 = findParent(u)`, `p2 = findParent(v)`  
        Step 5.2: If `p1 != p2`:  
                    Step 5.2.1: Add edge to MST  
                    Step 5.2.2: Union `p1` and `p2`  
                    Step 5.2.3: Add `w` to `totalWeight`  
Step 6: Print edges in MST and `totalWeight`  

## Stepwise :
1. Input number of vertices and edges  
2. Build adjacency list and edge list  
3. Display adjacency list  
4. Sort edges and initialize DSU structures  
5. Apply Kruskal's algorithm to select MST edges  
6. Print edges included in MST and total weight  

## Output:
Enter number of vertices: 5
Enter number of edges: 7
Enter edges as: src dest weight
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

Adjacency List Representation:
0 -> (1, 2) (3, 6)
1 -> (0, 2) (2, 3) (3, 8) (4, 5)
2 -> (1, 3) (4, 7)
3 -> (0, 6) (1, 8) (4, 9)
4 -> (1, 5) (2, 7) (3, 9)

Kruskal's MST Edges:
0 -- 1 | weight = 2
1 -- 2 | weight = 3
1 -- 4 | weight = 5
0 -- 3 | weight = 6
Total Weight of MST = 16

---