
#include <stdlib.h>
#include <stdio.h>


int parse(char* fname, char* inp_buff);

int main(int argc, char* argv[])
{
	int f_size = 0;

    char *buffer;

    if (argc != 2)
    {
        printf ("Usage: ./scc filename\n");
        return -1;
    }

    f_size = parse(argv[1], buffer);

    int n;
    for(n = 0; n < f_size; n++)
    {
        //printf("%s", buffer);
    }
        printf("%s", buffer);
    


    return 0;
}


int parse(char* fname, char* inp_buff)
{
    int c;
    FILE * fp;
    int f_size;
    int n = 0;
    int newline_c = 0;

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
        if( c != '\t' && c != ' ')
        {
            inp_buff[n++] = c;
        }
        
        //printf("%c", c);  
    }
       printf("%s", inp_buff);

    fclose(fp);

    return f_size;
}
