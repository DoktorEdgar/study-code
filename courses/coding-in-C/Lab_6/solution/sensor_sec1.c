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
 //using fprintf() to write to a file
 /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    FILE* f = fopen("sensor_sec2.txt", "w");           // Open the file "sensor_sec2.txt" in write mode and assign the file pointer to 'f'
    
    if (f)                                            // Check if the file was successfully opened
    {

        fprintf(f, "Merle sitzt neben mir.\n");     // Write a line of text to the file using fprintf()
        fprintf(f, "Sie programmiert sehr fleißig.\n");// Write another line of text to the file using fprintf()
        fclose(f);                                   // Close the file after writing is done to free up system resources
    
    }
 /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 //using fscanf() to read from a file
 /*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    FILE* f2 = fopen("sensor_sec2.txt", "r");          // Open the file "sensor_sec2.txt" in read mode and assign the file pointer to 'f2'
    
    char buffer[100];                                  // Declare a buffer to store the lines read from the file    
    
    if (f2)                                           // Check if the file was successfully opened
    {
      
        while (fgets(buffer, sizeof(buffer), f2))     // Read lines from the file one by one until End Of File (EOF) is reached
        {                                            // The fgets() function reads a line from the file pointed to by 'f2' and stores it in 'buffer'
            printf("%s", buffer);                    // Output the line read from the file to the standard output (console)
        }
        fclose(f2);                                  // Close the file after reading is done to free up system resources
    
    }





/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    struct Car fueling ={45.33, 70.0, 'M'};

    FuelingMyCar (&fueling);

    printf("Fuel level now: %f\n", fueling.ffuel_level);
   
    return 0;
}
