
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

Node *insert_node(Node *hd_ptr, char data);
Node *print_node(Node *hd_ptr);

int main(int argc, char* argv[])
{
	int f_size = 0;
	int counter = 0;
    char *buffer;
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
}

Node *print_node(Node *hd_ptr)
{
	while (hd_ptr != NULL)
	{
		printf(" %c", hd_ptr->data);
		hd_ptr = hd_ptr->next;
	}
}