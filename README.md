
# SCC Finder

Dongmin An,
adominic022@gmail.com
21600397@handong.edu

C Program to that Finds Strongly Connected Components from adjacency matrix.
Adjacency List, DFS discovery and Finish time is also found during the process.


## Finding SCC in graph

To Find SCC:

1. Call DFS(G) to find f[u], finish times for each vertex
2. Find Transpose(G)
3. Call DFS(Transpose(G)), of decreasing order of f[u]
4. Output vertices of each tree in forest as a SCC

--	As taken from CORMEN, 
[(Introduction to Algorithms)](https://mitpress.mit.edu/books/introduction-algorithms)

## Method in Code

* Parse input
* Create Linked List
* Find DFS discovery and finish time of linked list and its transpose
* Find & Output Strongly Connected Components


## Compiling options
Compile Options for Ubuntu:

	-lm 

Need to link math library for math.h

### Example program execution with GCC: 

```	
$ gcc scc.c -o scc
$ ./scc sample.data
```

### System & Compiler
Ubuntu 17.10,
GCC 7.2.0 (Ubuntu 7.2.0-8ubuntu3.2) 
