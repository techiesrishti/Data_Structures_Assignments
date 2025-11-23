# Assignment No: 7 (UNIT 5)  
# Title: Write a Program to implement Dijkstra’s algorithm to find shortest distance between two nodes of a user defined graph. Use Adjacency Matrix to represent a graph.

## Concepts Used:
- Graph representation using adjacency matrix  
- Dijkstra’s algorithm for shortest path  
- Greedy approach to select minimum distance vertex  
- STL containers: vector  
- Use of `INT_MAX` for initialization  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Initialize adjacency matrix `adjMatrix` of size V x V with 0  
Step 3: Input number of edges `E`  
Step 4: For each edge, input `src`, `dest`, `weight`  
        Step 4.1: Set `adjMatrix[src][dest] = weight`  
        Step 4.2: Set `adjMatrix[dest][src] = weight` (undirected graph)  
Step 5: Display adjacency matrix  

### 2. Find Minimum Distance Vertex
Step 1: Initialize `min = INT_MAX` and `index = -1`  
Step 2: For each vertex `v` from 0 to V-1:  
        Step 2.1: If `v` is not visited and `dist[v] <= min`  
                    Step 2.1.1: `min = dist[v]`  
                    Step 2.1.2: `index = v`  
Step 3: Return `index`  

### 3. Dijkstra's Algorithm
Step 1: Initialize `dist[]` array with `INT_MAX` for all vertices  
Step 2: Set `dist[src] = 0`  
Step 3: Initialize `visited[]` array as false  
Step 4: Repeat `V-1` times:  
        Step 4.1: Pick vertex `u` with minimum distance using `minDistance()`  
        Step 4.2: Mark `u` as visited  
        Step 4.3: For each vertex `v` adjacent to `u`:  
                    Step 4.3.1: If `v` is not visited and path through `u` is shorter  
                                Step 4.3.1.1: Update `dist[v] = dist[u] + weight(u,v)`  
Step 5: Print `dist[dest]` as shortest distance  

## Stepwise :
1. Input number of vertices and edges  
2. Build adjacency matrix  
3. Display adjacency matrix  
4. Input source and destination vertices  
5. Apply Dijkstra’s algorithm to compute shortest path  
6. Print shortest distance from source to destination  

## Output:
Enter number of vertices: 5
Enter number of edges: 7
Enter edges as: src dest weight
0 1 10
0 2 5
1 2 2
1 3 1
2 3 9
2 4 2
3 4 4

Adjacency Matrix:
0 10 5 0 0
10 0 2 1 0
5 2 0 9 2
0 1 9 0 4
0 0 2 4 0

Enter source vertex: 0
Enter destination vertex: 3

Shortest distance from 0 to 3 is: 8

---