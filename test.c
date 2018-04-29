<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>

typedef struct LList LList;
struct LList {
int value;
LList *next; };

int main()
{
LList *(*p)[3]; /* pointer to an array of 3 pointers to LList */
LList ll1 = {11};
LList ll2 = {22};
LList ll3 = {33};
size_t sizeofarray = sizeof*p/sizeof**p; /* calc arraysize at runtime here */
p = malloc( sizeofarray * sizeof**p ); /* allocate space for each LList-pointer in array */
(*p)[0] = &ll1;
(*p)[1] = &ll2;
(*p)[2] = &ll3;
/* test output here: */
printf("\n%d\n%d\n%d", ((*p)[0])->value,((*p)[1])->value,((*p)[2])->value);
free(p);

}
=======

	#include <stdio.h>

	void func(const char** pptr){

	    const char* str = "hello"; //store hello

	    *pptr = str; //set pointer from main point to hello string

	}

	int main() {

	    const char* ptr;

	    func(&ptr); //pass by reference?

	    printf("%s \n", ptr); //ptr should = hello

	    return 0;

	}
>>>>>>> 316537f280bb985b5c50c34db5cc2457a632973c
