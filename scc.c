
/***


Assumptions:
    We Assume that input matrix is of even colomn and width size, that is, it is an n x n matrix.


***/

#include <stdlib.h>
#include <stdio.h>


int parse(char* fname, char** inp_buff);
void transpose(char** src, char dst[], int size);

int main(int argc, char* argv[])
{
	int height = 0;
    char *buffer;


    if (argc != 2)
    {
        printf ("Usage: ./scc filename\n");
        return -1;
    }

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
    if (fp == NULL)
    {
        printf("failed to open file");
        return 0;
    }

    fseek (fp, 0L, SEEK_END);
    f_size = ftell(fp);
    fseek (fp, 0L, SEEK_SET); //or use rewind(fp);

    inp_buff = (char *) malloc(f_size);

    while ((c = fgetc(fp)) != EOF)
    {       
        if (c != '\t' && c != ' ')
        {
            inp_buff[n++] = c;
        }
        if (c == '\n')
        {
            height++;
        } 
        
        //printf("%c", c);  
    }
    //printf("%s\n", inp_buff);
    *buffer = inp_buff;

    fclose(fp);

    return height;
}
