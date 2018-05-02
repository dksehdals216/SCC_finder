/*

Dongmin An,
adominic@gmail.com


1. Call DFS(G) to compute finishing times f[u] for each vertex u

2. Compute Transpose(G)

3. Call DFS(Transpose(G)), but in the main loop of DFS, 
consider the vertices in order of decreasing f[u] 
(as computed in step 1)

4. Output the vertices of each tree in the depth-first forest 
of step 3 as a separate strong connected component

--	As taken from CORMEN, (Introduction to Algorithms)

*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

//Pre-defined variables for DFS node colors
#define white 0
#define grey 1
#define black 2

typedef struct Node
{
	char data;
	struct Node *next;
}Node;

void append_node(Node **hd_ptr, char in_data);
void printLL(Node *hd_ptr);
void freeLL(Node *hd_ptr);
void DFS(int pos, int counter, Node** hd_ptr, int *color, int *dtime, int *ftime);
void DFS_visit(int pos, int *time, int *color, int *dtime, int *ftime, Node** hd_ptr);
void f_SCC(int counter, Node** hd_ptr, int *ftime,  int* forest, int *color, char *name);
void insertion_keep(int *inp_cont, int *pos_cont, int counter);

int main(int argc, char* argv[])
{
    int c;
    int n = 0;
	int f_size = 0;
	int counter = 0;
    FILE * fp;
    char *buffer = NULL;

    int *res_ftime = NULL;
	int *res_dtime = NULL;
	int *rev_dtime = NULL;
	int *rev_ftime = NULL;

	int *color = NULL;
	int *forest = NULL;

    if (argc != 2)
    {
        printf ("Usage: ./scc filename\n");
        return -1;
    }

    fp = fopen (argv[1], "r");
    if (fp == NULL)
    {
        printf("failed to open file");
        return 0;
    }

    //Find file size using ftell
    fseek (fp, 0L, SEEK_END);
    f_size = ftell(fp);
    fseek (fp, 0L, SEEK_SET); 

    buffer = (char *) malloc(f_size);

    while ((c = fgetc(fp)) != EOF)
    {       
        if( c != '\t' && c != ' ' && c != '\n' && c != '\r')
        {
            buffer[n++] = c;
            if(!isalpha(c))
            {
            	counter++;
            }
        }
    }

	counter = sqrt(counter);
 	char name[counter];

 	Node *llist_arr[counter];
 	Node *rev_llist[counter];

 	//store labels A~Z in name array
 	for(n = 0; n < counter; n++)
 	{
 		llist_arr[n] = (Node*)malloc(sizeof(Node));
 		rev_llist[n] = (Node*)malloc(sizeof(Node));

 		name[n] = buffer[n];
 		llist_arr[n]->data = name[n];
 		rev_llist[n]->data = name[n];
 	}

 	//Add Nodes to Linked List from input
    for(n = 0; n < counter; n++)
    {
    	for(c = 1; c < counter + 1; c++)
    	{
    		if(buffer[c + ((counter + 1) * n) + counter] == '1')
    		{
    			append_node(&llist_arr[n]->next, name[c-1]);
    		}
    	}
    }
    for(n = 0; n < counter; n++)
    {
	    for(c = 0; c < counter; c++)
	    {
	    	if(buffer[n + ((counter + 1) * c) + counter + 1] == '1')
	    	{
	    		append_node(&rev_llist[n]->next, name[c]);
	    	}
	    }
	}

	//Print Linked List Repressenting Adj List
	printf("%s\n", "Adjacency List:");
    for (n = 0; n < counter; n++)
    {
	    printLL(llist_arr[n]);
	    printf("\n");
    }

    printf("\n");
	printf("%s\n", "Adjacency List (Transpose):");

    for (n = 0; n < counter; n++)
    {
    	printLL(rev_llist[n]);
    	printf("\n");
    }
    printf("\n");

	res_ftime =  malloc(counter * sizeof(int));
	res_dtime = malloc(counter * sizeof(int));
	rev_ftime =  malloc(counter * sizeof(int));
	rev_dtime =  malloc(counter * sizeof(int));

	DFS(0, counter, llist_arr, color, res_dtime, res_ftime);
	DFS(0, counter, rev_llist, color, rev_dtime, rev_ftime);

	//Print DFS & Transpose DFS Output
    printf("\n%s\n", "Discovery , Finish Time:");
	for(n = 0; n < counter; n++)
	{
		printf("%d  %d\n", res_dtime[n], res_ftime[n]);
	}

    printf("\n%s\n", "Discovery , Finish Time (Transpose):");
	for(n = 0; n < counter; n++)
	{
		printf("%d  %d\n", rev_dtime[n], rev_ftime[n]);
	}

	printf("\n");
	f_SCC(counter, rev_llist, res_ftime, forest, color, name);


	//Memory allocation Free
	free(buffer);
	for(n = 0; n < counter; n++)
	{
		freeLL(llist_arr[n]);
		freeLL(rev_llist[n]);
	}
	free(color);
	free(rev_ftime);
	free(rev_dtime);
	free(res_ftime);
	free(res_dtime);
	free(forest);

    return 0;
}

void f_SCC(int counter, Node** hd_ptr, int *ftime,  int* forest, int *color, char *name)
{
	int i, j, k;
	int *scc_d = malloc(counter * sizeof(int));
	int *scc_f = malloc(counter * sizeof(int));
	int *sort_ftime = malloc(counter * sizeof(int));
	forest = malloc(counter * sizeof(int)); 	//think of way to return 
	color = malloc(counter * sizeof(int));
	if (!color)
	{
		printf("Failed to allocate color!!\n");
	}

	insertion_keep(ftime, sort_ftime, counter);

	for(i = counter; i > 0; i--)
	{
		DFS(sort_ftime[i], counter, hd_ptr, color, scc_d, scc_f);
	}

	insertion_keep(scc_d, sort_ftime, counter);

	//Print output to screen
	k = 1;
	printf("%d%s", k, "-SCC: ");
	for(i = 0; i < counter; i++)
	{
		printf("%c ", name[sort_ftime[i]]);
		if(i != counter - 1 && scc_d[i]+1 != scc_d[i+1])
		{
			k++;
			printf("\n%d%s", k, "-SCC: ");
		}
	}
	printf("\n\n");

	free(color);
	free(scc_f);
	free(scc_d);
	free(sort_ftime);
	free(forest);
}


void append_node(Node** hd_ptr, char in_data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	Node* last = *hd_ptr;

	new->data = in_data;
	new->next = NULL;	//set new node next to null

	if (*hd_ptr == NULL)
	{
		*hd_ptr = new;
		return;
	}
	else {
		while (last->next != NULL)
		{
			last = last->next;
		}
	}
	last->next = new;
}

void printLL(Node *hd_ptr)
{
	while (hd_ptr != NULL)
	{
		printf("%c", hd_ptr->data);
			printf("->");

		hd_ptr = hd_ptr->next;
		if(hd_ptr == NULL)
		{
			printf("%s", "NULL");
		}
	}
}

void freeLL(Node *hd_ptr)
{
	Node* tmp;

	while(hd_ptr != NULL)
	{
		tmp = hd_ptr;
		hd_ptr = hd_ptr->next;
		free(tmp);
	}
}

void DFS(int pos, int counter, Node** hd_ptr, int *color, int *dtime, int *ftime)
{
	int i;
	int time = 0;
	int node_l = 0;

	color = malloc(counter * sizeof(int));
	if (!color)
	{
		printf("Failed to allocate color!!\n");
	}

	for(i = 0; i < counter; i++)
	{
		color[i] = white;
		//printf("%d", *color[i]);
	}

	for(i = pos; i < counter; i++)
	{
		if(color[i] == white)
		{
			DFS_visit(i, (&time), color, dtime, ftime, hd_ptr);
		}
	}
	for(i = 0; i < pos; i++)
	{
		if(color[i] == white)
		{
			DFS_visit(i, (&time), color, dtime, ftime, hd_ptr);
		}
	}

	free(color);
}

void DFS_visit(int pos, int *time, int *color, int *dtime, int *ftime, Node** hd_ptr)
{	
	int node_n;

	Node* tmp = hd_ptr[pos];
	color[pos] = grey;
	(*time)++;
	dtime[pos] = *time;

	while(tmp->next != NULL)
	{	
		tmp=tmp->next;
		if(color[tmp->data - 'A'] == white)
		{
			DFS_visit(tmp->data - 'A', time, color, dtime, ftime, hd_ptr);
		}
	}

	color[pos] = black;
	(*time)++;
	ftime[pos] = *time;
}

void insertion_keep(int *inp_cont, int *pos_cont, int counter)
{
	int tmp = 0;
	int n_tmp = 0;
	int i, j;

	for(i = 0; i < counter; i++)
	{
		pos_cont[i] = i;
	}

	for(i = 0; i < counter; i++)
	{
		j = i;
		while(j > 0 && inp_cont[j-1] > inp_cont[j])
		{
			tmp = inp_cont[j];
			inp_cont[j] = inp_cont[j-1];
			inp_cont[j-1] = tmp;
			
			n_tmp = pos_cont[j];
			pos_cont[j] = pos_cont[j-1];
			pos_cont[j-1] = n_tmp;

			j--;
		}
	}
}
