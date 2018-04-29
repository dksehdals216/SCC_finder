
/***


Assumptions:
    We Assume that input matrix is of even colomn and width size, that is, it is an n x n matrix.


***/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

typedef struct Node
{
	char data;
	struct Node *next;
	struct Node *tail;
}Node;

<<<<<<< HEAD
Node *insert_node(Node *hd_ptr, char data);
Node *print_node(Node *hd_ptr);

int main(int argc, char* argv[])
{
	int f_size = 0;
	int counter = 0;
=======
int parse(char* fname, char** inp_buff);
void transpose(char** src, char dst[], int size);

int main(int argc, char* argv[])
{
	int height = 0;
>>>>>>> 316537f280bb985b5c50c34db5cc2457a632973c
    char *buffer;
    int c;
    FILE * fp;
    int n = 0;


    if (argc != 2)
    {
        printf ("Usage: ./scc filename\n");
        return -1;
    }

<<<<<<< HEAD
    fp = fopen (argv[1], "r");
=======
    height = parse(argv[1], &buffer);

    char t_array[height * height];

    transpose(&buffer, t_array, height * height);
    
    free(buffer);
    //printf("%s", buffer);
    
    //printf("%d", height);

    return 0;
}

void transpose(char** src, char dst[], int size)
{

}

int parse(char* fname, char** buffer)
{
    int c;
    FILE * fp;
    int f_size;
    int n = 0;
    int newline_c = 0;
    char* inp_buff;
    int height = 0;

    fp = fopen (fname, "r");
>>>>>>> 316537f280bb985b5c50c34db5cc2457a632973c
    if (fp == NULL)
    {
        printf("failed to open file");
        return 0;
    }



    fseek (fp, 0L, SEEK_END);
    f_size = ftell(fp);
    fseek (fp, 0L, SEEK_SET); //or use rewind(fp);


    buffer = (char *) malloc(f_size);

    while ((c = fgetc(fp)) != EOF)
    {       
<<<<<<< HEAD
        if( c != '\t' && c != ' ' && c != '\n' && c != '\r')
=======
        if (c != '\t' && c != ' ')
>>>>>>> 316537f280bb985b5c50c34db5cc2457a632973c
        {
            buffer[n++] = c;
            if(!isalpha(c))
            {
            	counter++;
            }
        }
<<<<<<< HEAD
    }
=======
        if (c == '\n')
        {
            height++;
        } 
        
        //printf("%c", c);  
    }
    //printf("%s\n", inp_buff);
    *buffer = inp_buff;
>>>>>>> 316537f280bb985b5c50c34db5cc2457a632973c

	counter = sqrt(counter);

 	
 	char name[counter];

 	Node *llist_arr[counter];
 	//llist_arr = malloc(counter * sizeof(llist_arr *));


 	//store labels A~Z in name array
 	for(n = 0; n < counter; n++)
 	{
 		llist_arr[n] = (Node*)malloc(sizeof(Node));
 		name[n] = buffer[n];
 		llist_arr[n]->data = name[n];	
 		//printf("%c\n", llist_arr[n]->data);
 	}

    for(n = 0; n < counter; n++)
    {
    	for(c = 1; c < counter + 1; c++)
    	{
    		if(buffer[c + ((counter + 1) * n) + counter] == '1')
    		{
    			//llist_arr[n]->next = new;
    			//new->data =
    			//printf("%d\n", pos[n][i]);
    		}
    		//printf("%c", buffer[c + ((counter + 1) * n) + counter]);
    	}

    	//printf("\n");
    }


<<<<<<< HEAD
    free(buffer);
    for(n = 0; n < counter; n++)
    {
    	free(llist_arr[n]);
    }

    return 0;
}


Node *insert_node(Node *hd_ptr, char data)
{
	Node *new = (Node*)malloc(sizeof(Node));
	Node *current = hd_ptr;
	new->data = data;
	new->tail = NULL;

	if (hd_ptr->tail == NULL)
	{
		hd_ptr->tail = new;
	}
	else
	{
		while (current->tail != NULL)
		{
			current = current->tail;
		}
		current->tail = new->tail;
	}
	return hd_ptr;
=======
    return height;
>>>>>>> 316537f280bb985b5c50c34db5cc2457a632973c
}

Node *print_node(Node *hd_ptr)
{
	while (hd_ptr != NULL)
	{
		printf(" %c", hd_ptr->data);
		hd_ptr = hd_ptr->next;
	}
}