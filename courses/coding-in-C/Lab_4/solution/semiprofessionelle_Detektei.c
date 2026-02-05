#include <stdio.h>
#include <string.h>
/*---------------------------*/

char cweird[] = "Curly bird catches the worm";
char* cpcweird = cweird;
char** pntrpntr = &cpcweird;

int main ()
{
 printf("Die semi-professionelle Detektei hat folgende Informationen über den Verdächtigen:\n");
    printf("Name: %s\n", cweird);
    printf("ptr: %s\n", cpcweird);
    printf("dereferenced ptr: %p\n", (void*)cpcweird+1);
    printf("%p\n",(void*)&cpcweird);
   
    return 0;
}