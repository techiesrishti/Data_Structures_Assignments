# Assignment No: 9 (UNIT 5)  
# Title: Write a Program to implement Kruskal’s algorithm to find the minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.
# Same as [Assignment No. 3]

## Concepts Used:
- Graph representation using adjacency list  
- Minimum Spanning Tree (MST)  
- Kruskal’s Algorithm  
- Disjoint Set Union (Union-Find) with path compression and rank  
- STL containers: vector, pair  
- Sorting edges by weight using `sort()`  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Input number of edges `E`  
Step 3: Initialize adjacency list `adjList` as vector of vectors of `(vertex, weight)`  
Step 4: For each edge, input `u`, `v`, `weight`  
        Step 4.1: Add `(v, weight)` to `adjList[u]`  
        Step 4.2: Add `(u, weight)` to `adjList[v]`  
        Step 4.3: Store edge `(u, v, weight)` in `edges` list  

### 2. Display Adjacency List
Step 1: For each vertex `i` from 0 to `V-1`:  
        Step 1.1: Print `i ->`  
        Step 1.2: For each pair `(adjVertex, weight)` in `adjList[i]`:  
                    Print `(adjVertex, weight)`  

### 3. Kruskal's Algorithm
Step 1: Sort all edges in ascending order of weights  
Step 2: Initialize DSU with `V` vertices  
Step 3: Initialize `totalCost` = 0  
Step 4: For each edge `(u, v, weight)` in sorted edge list:  
        Step 4.1: If `find(u)` != `find(v)` in DSU:  
                    Step 4.1.1: Select this edge in MST  
                    Step 4.1.2: Add `weight` to `totalCost`  
                    Step 4.1.3: Union `u` and `v` in DSU  
Step 5: Print all selected edges for MST  
Step 6: Print `totalCost`  

### 4. DSU (Union-Find) Operations
#### Find Operation:
Step 1: If `parent[x] != x`, set `parent[x] = find(parent[x])`  
Step 2: Return `parent[x]`  

#### Union Operation:
Step 1: Find roots `rx = find(x)` and `ry = find(y)`  
Step 2: If `rx != ry`:  
        Step 2.1: Attach lower rank tree under higher rank tree  
        Step 2.2: If ranks are equal, make one root parent and increment its rank  

## Stepwise:
1. Input number of vertices `V`  
2. Input number of edges `E`  
3. Input edges `(u, v, weight)` and build adjacency list  
4. Display adjacency list  
5. Sort edges by weight  
6. Initialize DSU for `V` vertices  
7. Iterate through edges to select MST edges using DSU  
8. Print edges included in MST  
9. Print total MST cost  

## Output:
Enter number of vertices: 5
Enter number of edges: 7
Enter edges in format: u v weight
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9
----
Adjacency List:
0 -> (1, 2) (3, 6)
1 -> (0, 2) (2, 3) (3, 8) (4, 5)
2 -> (1, 3) (4, 7)
3 -> (0, 6) (1, 8) (4, 9)
4 -> (1, 5) (2, 7) (3, 9)
----
Kruskal's MST Edges:
0 -- 1 (wt = 2)
1 -- 2 (wt = 3)
1 -- 4 (wt = 5)
0 -- 3 (wt = 6)

Total MST Cost = 16

---
