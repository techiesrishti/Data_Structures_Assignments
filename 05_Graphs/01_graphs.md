# Assignment No: 1 (UNIT 5)  
# Title: Write a Program to accept a graph from a user and represent it with Adjacency Matrix and perform BFS and DFS traversals on it.  

## Concepts Used:
- Graph representation using adjacency matrix  
- Breadth-First Search (BFS) using queue  
- Depth-First Search (DFS) using stack  
- Vector and queue/stack STL containers  

## Pseudocode:

### 1. BFS Traversal
Step 1: Initialize a boolean array `visited` of size `numVertices` to false  
Step 2: Create an empty queue `q`  
Step 3: Enqueue the starting vertex into `q` and mark it visited  
Step 4: Repeat while `q` is not empty:  
        Step 4.1: Dequeue a vertex `v` from `q` and print it  
        Step 4.2: For each vertex `u` adjacent to `v` (i.e., `adjMatrix[v][u] == 1`):  
                    If `u` is not visited:  
                        Mark `u` visited  
                        Enqueue `u` into `q`  

### 2. DFS Traversal
Step 1: Initialize a boolean array `visited` of size `numVertices` to false  
Step 2: Create an empty stack `s`  
Step 3: Push the starting vertex into `s` and mark it visited  
Step 4: Repeat while `s` is not empty:  
        Step 4.1: Pop a vertex `v` from `s` and print it  
        Step 4.2: For each vertex `u` adjacent to `v` in reverse order (i.e., `adjMatrix[v][u] == 1`):  
                    If `u` is not visited:  
                        Mark `u` visited  
                        Push `u` into `s`  

## Stepwise:
1. Input number of vertices `numVertices`  
2. Input number of edges and each edge `(source, destination)`  
3. Build the adjacency matrix  
4. Print the adjacency matrix  
5. Input starting vertex for BFS and DFS  
6. Perform BFS traversal from the starting vertex  
7. Perform DFS traversal from the starting vertex  
8. Display BFS and DFS traversal sequences  

## Output:
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (source destination):
0 1
0 2
1 3
1 4
2 3
3 4

Adjacency Matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 1 0
0 1 1 0 1
0 1 0 1 0

Enter the starting vertex for traversal: 0

BFS Traversal starting from vertex 0: 0 1 2 3 4
DFS Traversal starting from vertex 0: 0 1 3 4 2

---