#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELDSIZE 12

int main ()
{

    int i_field [FIELDSIZE] = {0};
    int p1=2, p2=4, p3=6;
    i_field[p1]=1;
    i_field[p2]=1;
    i_field[p3]=1;
    /*-----------------------------------------------------*/
    int* p_i_field = i_field;
    /*-----------------------------------------------------*/
    int i_temp [FIELDSIZE] ={0};
    int* p_i_temp = i_temp;
    /*-----------------------------------------------------*/

    srand(time(NULL));
    for (int i_time = 0; i_time < 12; i_time++)
    {
        // 1. printing field
         for (int i=0; i<FIELDSIZE; i++)
            {
                printf("%d",*(i_field+i));
            }
            printf("\n");

        // 2. putting temp field zero
        for ( int i = 0; i < FIELDSIZE; i++) 
            {
                *(p_i_temp + i) = 0; 
            }

        // 3. move particles
            
            // 3.1 checking where the particles are
                for (int j = 0; j< FIELDSIZE; j++)
                {
                    if (*(p_i_field + j) == 1)
                    {
                        // 3.2 moving particle randomly
                        int i_direction = rand() % 2;
                        if (i_direction == 1)
                        {
                            if (j < FIELDSIZE - 1)
                            {
                                *(p_i_temp + j + 1) += 1;
                            }
                            else
                            {
                                *(p_i_temp + j) += 1;
                            }
                        }
                        else
                        {
                            if (j > 0)
                            {
                                *(p_i_temp + j - 1) += 1;
                            }
                            else
                            {
                                *(p_i_temp + j) += 1;
                            }
                        }
                         
                    }   
        }
        // 4. act upon collisions 
            for (int k = 0; k < FIELDSIZE; k++)
            {
                if (*(p_i_temp + k) > 1)
                {
                    *(p_i_temp + k) = 0;
                }
            }
        // 5. temp -> field copy
        for (int k = 0; k < FIELDSIZE; k++)
        {
            *(p_i_field + k) = *(p_i_temp + k);
        }
    }


    return 0;
}
