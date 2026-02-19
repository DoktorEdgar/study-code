#include <stdlib.h>
#include <stdio.h>
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 struct Car
    {
        float ffuel_level;
        float fmax_fuel_level;
        char cmodel;
    };
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/    
    void FuelingMyCar (struct Car* pc1)
    {
        
      float freadfuel = 0.0f;
      scanf("%f", &freadfuel);
      pc1->ffuel_level = pc1->ffuel_level + freadfuel > pc1->fmax_fuel_level ? pc1->fmax_fuel_level : pc1->ffuel_level + freadfuel;
    
    }    
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{   
    // reading a file character by character using getc() function
    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/    
    int ic;
    FILE* file;                                         // Declare a pointer to a FILE object
    file = fopen("sensor_sec1.txt", "r");               // Open the file "sensor_sec1.txt" in read mode and assign the file pointer to 'file'

    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    if (file)                                           // Check if the file was successfully opened
    {
    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        while ((ic = getc(file)) != EOF)                // Read characters from the file one by one until End Of File (EOF) is reached
                                                        // The getc() function reads the next character from the file pointed to by 'file' and returns it as an integer.
                                                        // The loop continues until getc() returns EOF, which indicates the end of the file
    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
        putchar (ic);                                   // Output the character read from the file to the standard output (console)
        fclose(file);                                   // Close the file after reading is done to free up system resources
    }

    /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    struct Car fueling ={45.33, 70.0, 'M'};

    FuelingMyCar (&fueling);

    printf("Fuel level now: %f\n", fueling.ffuel_level);
   
    return 0;
}
