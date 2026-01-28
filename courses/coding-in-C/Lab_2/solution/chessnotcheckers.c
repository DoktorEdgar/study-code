#include <stdio.h>

int main()
{
    int i, j;
    char reihen[] = {'A','B','C','D','E','F','G','H'};

    for (i=8; i>0; i--)
    {
        for (j=0; j<8 ; j++)
        {
            printf("%3c%d",reihen[j],i);
        }
        printf("\n");
    }

    for (i=8; i>0; i--)
    {
        for(j=0; j<8; j++)
        {
            if(((i+j)%2)>0)
            printf(" ss ");
        else
        printf(" ww ");
        }
        printf("\n");
        printf("\n");
    }
    for(j=0; j<8; j++)
    printf("%5c",reihen[j]);
    printf("\n");

     for (i=8; i>0; i--)
    {
        for(j=0; j<8; j++)
        {
            if(((i+j)%2)>0)
            printf("  ss");
        else
        printf("  ww");
        }
        printf("\n");
    }
    
    return 0;

}