#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h> // tolower-Funktion
/*---------------------------*/




void read_string (char* c_string, int i_lengthcstring)
{
    int i_lenghtcstring = 0;
    
    printf("Gib mir jetzt dein Wort:\n");
    fgets(c_string, 100, stdin);
    
    // Newline am Ende entfernen (fgets speichert auch das Newline)
    i_lenghtcstring = strlen(c_string);
    if (c_string[i_lenghtcstring - 1] == '\n') // Überprüfen, ob das letzte Zeichen ein Newline ist
    {
        c_string[i_lenghtcstring - 1] = '\0'; // Nullterminator setzen, um das Newline zu entfernen
    }

    *(c_string+1) = 99; // Ändert den 2. Buchstaben des Strings zu 'c' (ASCII 99)
    printf("Dein Wort ist jetzt: %s\n", c_string);
}

int main ()
{
    char cweird[] = "Curly bird catches the worm";
    char* cpcweird = cweird;
    char** pntrpntr = &cpcweird;
    /****************************************************************/
    /*printf("Die semi-professionelle Detektei hat folgende Informationen über den Verdächtigen:\n");
    printf("Name: %s\n", cweird); // Array ausgegeben
    printf("ptr: %s\n", cpcweird); // ausgeben worauf Pointer deutet 
    printf("dereferenced ptr: %p\n", (void*)cpcweird+1); // Adresse des Arrays
    printf("%p\n",(void*)&cpcweird); // Adresse des Pointers
   *cpcweird = 69; 
   *(cpcweird+1) = 97; // Werte ändern in ASCII
    printf("ptr: %s\n", cpcweird); */
    /****************************************************************/
    read_string(cweird, 0); // Funktion aufrufen, um String zu lesen und zu ändern
    /****************************************************************/
    printf("Wir gucken mal ob das Wort ein Palindrom ist: (case sensitive)\n");
    int i_length = strlen(cweird);
    int i_length_half = i_length /2;
    printf("i_length ist %d\n", i_length);
    printf("i_length_half ist %d\n", i_length_half);
    
    int is_palindrome = 1; // Annahme: Es ist ein Palindrom, bis das Gegenteil bewiesen ist
    for (int i = 0; i < i_length_half; i++) 
    {
        printf("Vergleiche '%c' mit '%c'\n", cweird[i], cweird[i_length - 1 - i]);
        printf(" i ist %d\n", i);

        if (cweird[i] != cweird[i_length - 1 - i])
         {
            is_palindrome = 0; // Es ist kein Palindrom
            break;
        }
    }
    /****************************************************************/

    if (is_palindrome == 1) 
    {
        printf("Ja, das Wort '%s' ist ein Palindrom!\n", cweird);
    } 
        else 
    {
        printf("Nein, das Wort '%s' ist kein Palindrom.\n", cweird);
    }

    /****************************************************************/

    printf("Und jetzt einmal nicht case sensitive:\n");
    is_palindrome = 1; // Annahme: Es ist ein Palindrom, bis das Gegenteil bewiesen ist
    
    for (int i = 0; i < i_length / 2; i++)
     {
        if (tolower(cweird[i]) != tolower(cweird[i_length - 1 - i])) 
        
        {
            is_palindrome = 0; // Es ist kein Palindrom
            break;
        }
    }   

    if (is_palindrome == 1) 
    {
        printf("Ja, das Wort '%s' ist ein Palindrom (case insensitive)!\n", cweird);
    } 
    
    else 
    {
        printf("Nein, das Wort '%s' ist kein Palindrom (case insensitive).\n", cweird);
    }
    return 0;
}