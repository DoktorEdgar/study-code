/*
 * File: generate_sensor_files.c
 *
 * Section II helper program for Lab 6.  The goal is to create two
 * text files that reproduce exactly the measurement files used in
 * Section I (`sensor1.txt` and `sensor2.txt`).  The data consists of
 * 3000 samples taken every 0.02 seconds; the signal is a constant
 * baseline (0.2 for sensor1, 0.3 for sensor2) with three rectangular
 * pulses that correspond to the detection intervals listed in the
 * lab description.
 *
 * The program simply writes the time/probability pairs with
 * fprintf() and closes the files.  Running it will overwrite any
 * existing `sensor1.txt` and `sensor2.txt` in the current directory.
 */

#include <stdio.h>

#define SAMPLES 3000
#define DT 0.02

int main(void)
{
    FILE *f1 = fopen("sensor1.txt", "w");
    FILE *f2 = fopen("sensor2.txt", "w");
    if (f1 == NULL || f2 == NULL)
    {
        perror("fopen");
        return 1;
    }

    for (int i = 0; i < SAMPLES; ++i)
    {
        double t = i * DT;

        /* baseline probabilities */
        double p1 = 0.2;
        double p2 = 0.3;

        /* sensor 1 pulse windows */
        if ((t >= 10.0 && t <= 20.0) ||
            (t >= 30.0 && t <= 40.0) ||
            (t >= 45.0 && t <= 55.0))
        {
            p1 = 0.9;
        }

        /* sensor 2 pulse windows */
        if ((t >= 15.0 && t <= 25.0) ||
            (t >= 30.0 && t <= 40.0) ||
            (t >= 50.0 && t <= 60.0))
        {
            p2 = 0.85;
        }

        fprintf(f1, "%.2f %.3f\n", t, p1);
        fprintf(f2, "%.2f %.3f\n", t, p2);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
