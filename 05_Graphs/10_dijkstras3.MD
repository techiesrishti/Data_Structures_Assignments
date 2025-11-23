# Assignment No: 10 (UNIT 5)  
# Title: Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. Use Adjacency List to represent a graph.

## Concepts Used:
- Graph representation using adjacency list  
- Weighted undirected graph  
- Dijkstra's algorithm for shortest path  
- Priority queue (min-heap) for selecting minimum distance vertex  
- STL containers: vector, pair, priority_queue  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Initialize adjacency list `adjList` of size V  
Step 3: Input number of edges `E`  
Step 4: For each edge, input `src`, `dest`, `weight`  
        Step 4.1: Add `(dest, weight)` to `adjList[src]`  
        Step 4.2: Add `(src, weight)` to `adjList[dest]` (undirected)  

### 2. Display Adjacency List
Step 1: For each vertex `v` from 0 to V-1:  
        Step 1.1: Print `v -> `  
        Step 1.2: For each neighbor `(neighbor, weight)` in `adjList[v]`:  
                    Print `(neighbor, w=weight)`  

### 3. Dijkstra's Algorithm
Step 1: Initialize `dist[V]` = infinity, `dist[start] = 0`  
Step 2: Initialize priority queue `pq` and push `(0, start)`  
Step 3: While `pq` is not empty:  
        Step 3.1: Pop `(currentDist, currentNode)` from `pq`  
        Step 3.2: If `currentDist > dist[currentNode]`, continue  
        Step 3.3: For each neighbor `(next, weight)` of `currentNode`:  
                    Step 3.3.1: If `dist[currentNode] + weight < dist[next]`:  
                                  Update `dist[next] = dist[currentNode] + weight`  
                                  Push `(dist[next], next)` to `pq`  
Step 4: Print `dist[end]` as shortest distance from start to end  

## Stepwise :
1. Input number of vertices and edges  
2. Build adjacency list  
3. Display adjacency list  
4. Input source and destination vertices  
5. Apply Dijkstra’s algorithm using min-priority queue  
6. Print shortest distance from source to destination  

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

Adjacency List:
0 -> (1, w=2) (3, w=6)
1 -> (0, w=2) (2, w=3) (3, w=8) (4, w=5)
2 -> (1, w=3) (4, w=7)
3 -> (0, w=6) (1, w=8) (4, w=9)
4 -> (1, w=5) (2, w=7) (3, w=9)

Enter source vertex: 0
Enter destination vertex: 4

Shortest distance from 0 to 4 is: 7

---