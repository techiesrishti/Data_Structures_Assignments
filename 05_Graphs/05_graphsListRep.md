# Assignment No: 5 (UNIT 5)  
# Title: Write a Program to accept a graph from a user and represent it with Adjacency List and perform BFS and DFS traversals on it.

## Concepts Used:
- Graph representation using adjacency list  
- Breadth-First Search (BFS) traversal  
- Depth-First Search (DFS) traversal using stack  
- STL containers: vector, queue, stack  
- Iterative traversal of graph nodes  

## Pseudocode:

### 1. Graph Initialization
Step 1: Input number of vertices `V`  
Step 2: Initialize adjacency list `adjList` as vector of vectors  
Step 3: Input number of edges `E`  
Step 4: For each edge, input `u`, `v`  
        Step 4.1: Add `v` to `adjList[u]`  
        Step 4.2: Add `u` to `adjList[v]` (undirected graph)  

### 2. Display Adjacency List
Step 1: For each vertex `i` from 0 to `V-1`:  
        Step 1.1: Print `i ->`  
        Step 1.2: For each neighbor in `adjList[i]`:  
                    Print neighbor  

### 3. BFS Traversal
Step 1: Input starting vertex `start`  
Step 2: Initialize `visited[]` array as false  
Step 3: Initialize queue `q` and push `start`  
Step 4: Mark `start` as visited  
Step 5: While `q` is not empty:  
        Step 5.1: Pop `current` from `q`  
        Step 5.2: Print `current`  
        Step 5.3: For each neighbor of `current`:  
                    If not visited:  
                        Mark visited and push into `q`  

### 4. DFS Traversal
Step 1: Input starting vertex `start`  
Step 2: Initialize `visited[]` array as false  
Step 3: Initialize stack `s` and push `start`  
Step 4: Mark `start` as visited  
Step 5: While `s` is not empty:  
        Step 5.1: Pop `current` from `s`  
        Step 5.2: Print `current`  
        Step 5.3: For each neighbor of `current` in reverse order:  
                    If not visited:  
                        Mark visited and push into `s`  

## Stepwise :
1. Input number of vertices and edges  
2. Input edges to build adjacency list  
3. Display adjacency list for verification  
4. Input starting vertex for traversal  
5. Perform BFS and display traversal order  
6. Perform DFS and display traversal order  

## Output:
Enter the number of vertices: 5
Enter the number of edges: 6
Enter the edges (source destination):
0 1
0 2
1 2
1 3
2 4
3 4

Adjacency List:
0 -> 1 2
1 -> 0 2 3
2 -> 0 1 4
3 -> 1 4
4 -> 2 3

Enter the starting vertex for traversal: 0

BFS Traversal starting from vertex 0: 0 1 2 3 4

DFS Traversal starting from vertex 0: 0 1 2 4 3

---