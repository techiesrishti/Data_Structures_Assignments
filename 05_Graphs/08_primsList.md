# Assignment No: 8 (UNIT 5)  
# Title: Write a Program to implement Prim’s algorithm to find minimum spanning tree of a user defined graph. Use Adjacency List to represent a graph.

## Concepts Used:
- Graph representation using adjacency list  
- Prim's algorithm for MST  
- Priority queue for selecting minimum weight edge  
- Greedy algorithm concept  
- STL containers: vector, pair, priority_queue  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Initialize adjacency list `adjList` of size V  
Step 3: Input number of edges `E`  
Step 4: For each edge, input `src`, `dest`, `weight`  
        Step 4.1: Add edge to adjacency list as `(dest, weight)`  
        Step 4.2: Add reverse edge `(src, weight)` for undirected graph  

### 2. Display Adjacency List
Step 1: For each vertex `v` from 0 to V-1:  
        Step 1.1: Print `v -> `  
        Step 1.2: For each edge `(neighbor, weight)` in `adjList[v]`:  
                    Print `(neighbor, weight)`  

### 3. Prim's Algorithm
Step 1: Initialize arrays:  
        `key[V]` = INT_MAX  
        `parent[V]` = -1  
        `inMST[V]` = false  
Step 2: Set `key[start] = 0`  
Step 3: Push `(0, start)` to min-priority queue `pq`  
Step 4: While `pq` is not empty:  
        Step 4.1: Pop vertex `u` with minimum key from `pq`  
        Step 4.2: If `u` already in MST, continue  
        Step 4.3: Mark `u` as included in MST  
        Step 4.4: For each neighbor `v` of `u`:  
                    Step 4.4.1: If `v` not in MST and `weight(u,v) < key[v]`  
                                Step 4.4.1.1: Update `key[v] = weight(u,v)`  
                                Step 4.4.1.2: Update `parent[v] = u`  
                                Step 4.4.1.3: Push `(key[v], v)` to `pq`  
Step 5: Print MST edges and total weight  

## Stepwise :
1. Input number of vertices and edges  
2. Build adjacency list  
3. Display adjacency list  
4. Input starting vertex for Prim's algorithm  
5. Apply Prim’s algorithm to compute MST  
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

Enter starting vertex for Prim's: 0

Minimum Spanning Tree (Prim's Algorithm):
0 -- 1 | weight_sp = 2
1 -- 2 | weight_sp = 3
1 -- 4 | weight_sp = 5
0 -- 3 | weight_sp = 6
Total Weight of MST = 16

---