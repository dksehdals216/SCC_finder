
# SCC Finder

Dongmin An,
adominic022@gmail.com
21600397@handong.edu

C Program to that Finds Strongly Connected Components from adjacency matrix.
Adjacency List, DFS discovery and Finish time is also found during the process.


## How to find scc
To Find SCC:
1. Call DFS(G) to find f[u], finish times for each vertex
2. Find Transpose(G)
3. Call DFS(Transpose(G)), of decreasing order of f[u]
4. Output vertices of each tree in forest as a SCC

--	As taken from CORMEN, (Introduction to Algorithms)

## method
* Parse input
* Create Linked List
* Find DFS discovery and finish time of linked list and its transpose
* Find & Output Strongly Connected Components


## running options
Compile Options for Ubuntu:
	-lm (Need to link math library for math.h)

### example: 
'''
	gcc scc.c -o scc
	./scc sample.data
'''

### system & compiler
Ubuntu 17.10,
GCC 7.2.0 (Ubuntu 7.2.0-8ubuntu3.2) 
