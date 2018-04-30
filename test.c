
#include <stdio.h>
#include <stdlib.h>

int main()
{

char letter = 'A';
int num;

if (letter >= 'A' && letter <= 'Z')
  num = letter - 'A';
else if (letter >= 'a' && letter <= 'z')
  num = letter - 'a';

printf("%d", num);
}