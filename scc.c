
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
void DFS(int, int, int*, Node **hd_ptr);
//void DFS(int counter, Node** hd_ptr, int *color, int *dtime, int *ftime);
//void DFS_visit(int *color, int pos, int counter, int *dtime, int *ftime, int *time, Node** hd_ptr);
//void print_time(int *dtime, int *ftime, int counter);


int main(int argc, char* argv[])
{
	int err = 0;
	int f_size = 0;
	int counter = 0;
    char *buffer = NULL;
    int *ftime = NULL;
	int *dtime = NULL;
	int *color = NULL;
    int c;
    FILE * fp;
    int n = 0;

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



    fseek (fp, 0L, SEEK_END);
    f_size = ftell(fp);
    fseek (fp, 0L, SEEK_SET); //or use rewind(fp);


    buffer = (char *) malloc(f_size);
	if (!buffer)
	{
		printf("Failed to allocate buffer!!\n");
	}

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
 	//llist_arr = malloc(counter * sizeof(llist_arr *));


 	//store labels A~Z in name array
 	for(n = 0; n < counter; n++)
 	{
 		llist_arr[n] = (Node*)malloc(sizeof(Node));
 		rev_llist[n] = (Node*)malloc(sizeof(Node));
		if (!llist_arr[n])
		{
			printf("Failed to allocate Linked List!!\n");
		}
		if (!rev_llist[n])
		{
			printf("Failed to allocate Reversed List!!\n");
		}

 		name[n] = buffer[n];
 		llist_arr[n]->data = name[n];
 		rev_llist[n]->data = name[n];
 		//printf("%c\n", llist_arr[n]->data);
 	}

    for(n = 0; n < counter; n++)
    {
    	for(c = 1; c < counter + 1; c++)
    	{
    		if(buffer[c + ((counter + 1) * n) + counter] == '1')
    		{
    			append_node(&llist_arr[n]->next, name[c-1]);
    			//new->data =
    			//printf("%d\n", pos[n][i]);
    		}
    		//printf("%c", buffer[c + ((counter + 1) * n) + counter]);
    	}
    	//printf("\n");
    }

    for(n = 0; n < counter; n++)
    {
	    for(c = 0; c < counter; c++)
	    {
	    	if(buffer[n + ((counter + 1) * c) + counter + 1] == '1')
	    	{
	    		append_node(&rev_llist[n]->next, name[c]);
	    	}
	    	//printf("%c", buffer[c + ((counter + 1) * n) + counter + 1]);
	    	
	    }
		//printf("\n");
	}

    for (n = 0; n < counter; n++)
    {
	    printLL(llist_arr[n]);
	    printf("\n");
    }

    printf("\n");

    for (n = 0; n < counter; n++)
    {
    	printLL(rev_llist[n]);
    	printf("\n");
    }

    printf("\n");
	
	ftime =  malloc(counter * sizeof(int));
	if (!ftime)
	{
		printf("Failed to allocate ftime!!\n");
	}

	dtime = malloc(counter * sizeof(int));
	if (!dtime)
	{
		printf("Failed to allocate dtime!!\n");
	}

	color = malloc(counter * sizeof(int));
	if (!color)
	{
		printf("Failed to allocate color!!\n");
	}
	
    int *visited = malloc(counter * sizeof(int));

    for(n = 0; n < counter; n++)
    {
        visited[n] = 0;
    }

    DFS(0, counter, visited, llist_arr);

    //DFS(counter, llist_arr, color, dtime, ftime);

    free(buffer);
    for(n = 0; n < counter; n++)
    {
        freeLL(llist_arr[n]);
        freeLL(rev_llist[n]);
    }

    free(color);
    free(dtime);
    free(ftime);
    return err;


    return 0;
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

void DFS(int i, int n, int* visited, Node **hd_ptr)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    Node* tmp = *hd_ptr;

    for(j = 0; j < n; j++)
    {
        if(!visited[j] && *hd_ptr != NULL)
        {
            DFS(j, n, visited, hd_ptr);
        }
    }
}
/*
void DFS(int counter, Node** hd_ptr, int *color, int *dtime, int *ftime)
{
	int i;
	int time = 0;

	for(i = 0; i < counter; i++)
	{
		color[i] = white;
	}

	for(i = 0; i < counter; i++)
	{
		if(color[i] == white)
		{
			DFS_visit(color, i, counter, dtime, ftime, &time, hd_ptr);
		}
	}

    for (i = 0; i < counter; i++)
    {
        printf("%d\n", dtime[i]);
    }

    printf("\n");
    for (i = 0; i < counter; i++)
    {
        printf("%d\n", ftime[i]);
    }

}

void DFS_visit(int *color, int pos, int counter, int *dtime, int *ftime, int *time, Node** hd_ptr)
{
	int i = 0;
    int num;
    char letter;
	Node *tmp;
	tmp = *hd_ptr;

	color[pos] = grey;
	time++;
	dtime[pos] = *time;

	for(i = 0; i < counter; i++)
	{
	    while(tmp!=NULL)
	    {
            
	    	i=tmp->data;
	    	if(color[i] == white)
	    	{
	    		DFS_visit(color, i, counter, dtime, ftime, time, hd_ptr);
	    	}
	    	tmp=tmp->next;
	    }

	}

	color[pos] = black;
	time++;
	ftime[pos] = *time;

    //print_time(dtime, ftime, counter);
}*/
/*
void print_time(int *dtime, int *ftime, int counter)
{
    int i;
letter = tmp->data;
            if (letter >= 'A' && letter <= 'Z')
            {
                num = letter - 'A';
            }

}
*/
