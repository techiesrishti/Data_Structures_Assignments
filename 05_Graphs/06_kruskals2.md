# Assignment No: 6 (UNIT 5)  
# Title: Write a Program to implement Kruskal’s algorithm to find the minimum spanning tree of a user defined graph. Use Adjacency Matrix to represent a graph. 

## Concepts Used:
- Graph representation using adjacency matrix  
- Minimum Spanning Tree (MST) using Kruskal’s algorithm  
- Disjoint Set Union (DSU) / Union-Find for cycle detection  
- Sorting edges by weight  
- STL containers: vector, algorithm  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Initialize adjacency matrix `adjMatrix` of size V x V with 0  
Step 3: Input number of edges `E`  
Step 4: For each edge, input `src`, `dest`, `weight`  
        Step 4.1: Set `adjMatrix[src][dest] = weight`  
        Step 4.2: Set `adjMatrix[dest][src] = weight` (undirected graph)  

### 2. Display Adjacency Matrix
Step 1: For each vertex `i` from 0 to `V-1`:  
        Step 1.1: For each vertex `j` from 0 to `V-1`:  
                    Print `adjMatrix[i][j]`  

### 3. Kruskal's Algorithm
Step 1: Extract all edges from adjacency matrix into edge list  
Step 2: Sort edges by increasing weight  
Step 3: Initialize `parent[]` array for DSU  
Step 4: Initialize `rank[]` array as 0 for DSU  
Step 5: Initialize empty MST list and `totalCost = 0`  
Step 6: For each edge in sorted edge list:  
        Step 6.1: Find parents of `src` and `dest`  
        Step 6.2: If parents are different (no cycle):  
                    Add edge to MST  
                    Add weight to `totalCost`  
                    Union the sets of `src` and `dest`  
Step 7: Print edges of MST and `totalCost`  

## Stepwise :
1. Input number of vertices and edges  
2. Input edges to build adjacency matrix  
3. Display adjacency matrix  
4. Extract edges and sort by weight  
5. Apply Kruskal’s algorithm using DSU  
6. Display MST edges and total minimum cost  

## Output:
Enter number of vertices: 4
Enter number of edges: 5
Enter edges as: src dest weight
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Adjacency Matrix:
0 10 6 5
10 0 0 15
6 0 0 4
5 15 4 0

Minimum Spanning Tree (Kruskal):
2 - 3 (weight = 4)
0 - 3 (weight = 5)
0 - 1 (weight = 10)
Total Minimum Cost: 19

---