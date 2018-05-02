
Dongmin An,
	adominic022@gmail.com
	21600397@handong.edu

1. Parse input
2. Create Linked List
3. Find DFS discovery and finish time of linked list and its transpose
4. Find & Output Strongly Connected Components

	To Find SCC:
		1. Call DFS(G) to find f[u], finish times for each vertex
		2. Find Transpose(G)
		3. Call DFS(Transpose(G)), of decreasing order of f[u]
		4. Output vertices of each tree in forest as a SCC

	--	As taken from CORMEN, (Introduction to Algorithms)


Compile Options for Ubuntu:
	-lm (Need to link math library for math.h)

Ubuntu 17.10,
GCC 7.2.0 (Ubuntu 7.2.0-8ubuntu3.2) 
