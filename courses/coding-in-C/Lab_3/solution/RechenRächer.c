#include <stdio.h>
/*----------------------------------*/

int main(void)
{
    float fa, fb, fc;
    char cop;
    char again = 'n';

    do {
        printf("Heute wird ohne Nieren gerechnet, bitte gib die erste Zahl: ");
        if (scanf("%f", &fa) != 1)
         {
            printf("Willst du etwa nicht rechnen?\n");
            return 1;
        }

        printf("Nun die zweite Zahl: ");
        if (scanf("%f", &fb) != 1) 
        {
            printf("Willst du etwa nicht rechnen?\n");
            return 1;
        }

        printf("Deine Zahlen sind: %f und %f\n", fa, fb);

        printf("Wie möchtest du rechnen? ( + , - , * , / ): ");

        if (scanf(" %c", &cop) != 1) 
        {
            printf("Doch keine Lusrt aufs Rechnen?\n");
            return 1;
        }

        switch (cop) 
        {
            case '+':
                fc = fa + fb;
                printf("Additieren ohne Nieren. \n Du willst folgendes berechnen:%f + %f = %f\n", fa, fb, fc);
                break;
            case '-':
                fc = fa - fb;
                printf("Subtrahieren ohne Nieren. \n Du willst folgendes berechnen:%f - %f = %f\n", fa, fb, fc);
                break;
            case '*':
                fc = fa * fb;
                printf("Multiplizieren ohne Nieren. \n Du willst folgendes berechnen:%f * %f = %f\n", fa, fb, fc);
                break;
            case '/':
                if (fb == 0.0f) {
                    printf("Du wolltest mit Nieren dividieren. Das mag ich nicht. Geh ins Gefängnis, geh nicht über Los!\n");
                } else {
                    fc = fa / fb;
                    printf("Dividieren ohne Nieren. \n Du willst folgendes berechnen:%f / %f = %f\n", fa, fb, fc);
                }
                break;
            default:
                printf("Hm das kenn ich nicht %c\n", cop);
                break;
        }

        printf("Noch eine Rechnung? (j/n): ");
    if (scanf(" %c", &again) != 1) 
    {
            return 0;
        }

    } 
    
    while (again == 'j' || again == 'J');

    return 0;
}
