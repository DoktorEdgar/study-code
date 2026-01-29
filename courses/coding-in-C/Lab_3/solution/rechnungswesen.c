#include <stdio.h> // includes

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
float fa=0, fb=0, fc;
int main ()
{
    printf("Heute wird gerchnet, dafür braucht man Zahlen. Bitte erlaube mir nach einer rationalen Zahl zu fragen\n");
    scanf("%f",&fa);
    printf("Nun benötigen wir eine zweite, rationale Zahl zum Operieren\n");
    scanf("%f",&fb);
    printf("Deine Zahlen sind: %f und %f\n", fa, fb);

    printf("Wie möchtest du rechnen? ( + , - , * , / )\n");
    char cop;
    scanf(" %c", &cop);
    if(cop == '+')
    {
        printf("Additieren ohne Nieren. \n Du willst folgendes berechnen: %f + %f\n", fa, fb);
        fc = fa + fb;
        printf("Das Ergebnis ist %f + %f = %f\n", fa, fb, fc);
    }
    if(cop == '-')
    {
        printf("Subtrahieren ohne Nieren. \n Du willst folgendes berechnen: %f - %f\n", fa, fb);
        fc = fa - fb;
        printf("Das Ergebnis ist %f - %f = %f\n", fa, fb, fc);
    }
    if(cop == '*')
    {
        printf("Multiplizieren ohne Nieren. \n Du willst folgendes berechnen: %f * %f\n", fa, fb);
        fc = fa * fb;
        printf("Das Ergebnis ist %f * %f = %f\n", fa, fb, fc);
    }
    if(cop == '/')
    {
        if(fb == 0)
        {
            printf("Du wolltest mit Nieren dividieren. Das mag ich nicht. Geh ins Gefängnis!\n");
        }
        else
        {
            printf("Dividieren ohne Nieren. \n Du willst folgendes berechnen: %f / %f\n", fa, fb);
            fc = fa / fb;
            printf("Das Ergebnis ist %f / %f = %f\n", fa, fb, fc);
        }
    }
    return 0;
}