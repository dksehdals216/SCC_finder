
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