# Assignment No: 4 (UNIT 5)  
# Title: Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. Use Adjacency List to represent a graph. 

## Concepts Used:
- Weighted Graph representation using adjacency list  
- Dijkstra's algorithm  
- Priority queue (min-heap)  
- STL containers: vector, pair  
- Finding shortest distance between source and destination nodes  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Input number of edges `E`  
Step 3: Initialize adjacency list `adj` as vector of vectors of edges `(to, weight)`  
Step 4: For each edge, input `u`, `v`, `w`  
        Step 4.1: Add edge `(v, w)` to `adj[u]`  
        Step 4.2: Add edge `(u, w)` to `adj[v]` (undirected graph)  

### 2. Display Adjacency List
Step 1: For each vertex `i` from 0 to `V-1`:  
        Step 1.1: Print `i ->`  
        Step 1.2: For each edge `(to, weight)` in `adj[i]`:  
                    Print `(to, w=weight)`  

### 3. Dijkstra’s Algorithm
Step 1: Input source node `src` and destination node `dest`  
Step 2: Initialize `dist[]` array with infinity, set `dist[src] = 0`  
Step 3: Initialize a priority queue `pq` and push `(0, src)`  
Step 4: While `pq` is not empty:  
        Step 4.1: Pop `(d, node)` from `pq`  
        Step 4.2: If `d > dist[node]`, continue  
        Step 4.3: For each edge `(next, weight)` of `node`:  
                    Step 4.3.1: If `dist[node] + weight < dist[next]`  
                                Step 4.3.1.1: Update `dist[next] = dist[node] + weight`  
                                Step 4.3.1.2: Push `(dist[next], next)` into `pq`  
Step 5: If `dist[dest]` is infinity, print "No path exists"  
Step 6: Else print `dist[dest]` as shortest distance  

## Stepwise :
1. Input number of vertices `V` and edges `E`  
2. Input all edges `(u, v, weight)` to build adjacency list  
3. Display adjacency list  
4. Input source and destination nodes  
5. Initialize distance array and priority queue  
6. Run Dijkstra’s algorithm using priority queue  
7. Print shortest distance between source and destination or report no path  

## Output:
Enter number of vertices: 5
Enter number of edges: 6
Enter edges in format: u v w
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1

Adjacency List Representation:
0 -> (1, w=2) (2, w=4)
1 -> (0, w=2) (2, w=1) (3, w=7)
2 -> (0, w=4) (1, w=1) (4, w=3)
3 -> (1, w=7) (4, w=1)
4 -> (2, w=3) (3, w=1)

Enter source node: 0
Enter destination node: 3

Shortest distance from 0 to 3 = 6

---