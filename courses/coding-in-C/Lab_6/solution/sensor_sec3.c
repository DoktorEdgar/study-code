#include <stdio.h>
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef struct SensorData
{
    float ftime;
    double dprobability;
} SensorData;

typedef struct Sensor
{
    int iID;
    double dthreshold;
    struct SensorData data[3001];
    int iobject_detected[3001];
} Sensor;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Function declarations

void load_sensor_data(Sensor* s, const char* filename);
void compute_detection(Sensor *s);
void print_intervals(Sensor *s);

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Function to load sensor data from a file

void load_sensor_data(Sensor* s, const char* filename)
{
    FILE* f = fopen(filename, "r");
    if (!f) 
    {
        printf("Error opening file %s\n", filename);
        return;
    }

    int i = 0;
    while (fscanf(f, "%f %lf", &s->data[i].ftime, &s->data[i].dprobability) == 2) // Read time and probability from the file into the sensor data structure
     //&s ->data[i].ftime is the address of the ftime field in the i-th element of the data array, and &s->data[i].dprobability is the address of the dprobability field in the same element. The fscanf function will read a float value from the file and store it in s->data[i].ftime, and read a double value and store it in s->data[i].dprobability.
    {
        i++;
        if (i >= 3001) break;
    }

    fclose(f);
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Function to compute object detection based on the threshold

void compute_detection(Sensor* s)
{
    for (int i = 0; i < 3001; i++) 
    {
        if (s->data[i].dprobability > s->dthreshold)    // If the probability exceeds the threshold, mark as detected
            s->iobject_detected[i] = 1;
        else                                            // Otherwise, mark as not detected
            s->iobject_detected[i] = 0;
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Function to print intervals of object detection

void print_intervals(Sensor* s)
{
    int active = 0;         // Flag to indicate if we are currently in an active interval
    float start = 0;        // Variable to store the start time of an interval

    for (int i = 0; i < 3001; i++)  // Loop through all data points
    {
        if (!active /*not active*/ && /*AND*/s->iobject_detected[i] == 1) // If we are not currently in an active interval and an object is detected
        {
            start = s->data[i].ftime;               // Record the start time of the interval
            active = 1;
        }

        if (active && s->iobject_detected[i] == 0) // If we are currently in an active interval and no object is detected
        {
            float end = s->data[i-1].ftime;                      // Record the end time of the interval (using the previous time point since the current one is not detected)
            printf("Start: %.2f s  End: %.2f s\n", start, end);  // Print the interval
            active = 0;                                          // Reset the active flag for the next interval
        }
    }

    if (active)     // If we end the loop while still in an active interval, we need to close that interval
    {
        float end = s->data[3000].ftime;                        // Record the end time of the interval (using the last time point since we are still active)
        printf("Start: %.2f s  End: %.2f s\n", start, end);     // Print the final interval
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    // Initialize sensors
    Sensor sensor1, sensor2;
    sensor1.iID = 1;
    sensor1.dthreshold = 0.8;
    sensor2.iID = 2;
    sensor2.dthreshold = 0.7;

    // Load data from files
    load_sensor_data(&sensor1, "../sensor1.txt");
    load_sensor_data(&sensor2, "../sensor2.txt");

    // Compute detection for both sensors
    compute_detection(&sensor1);
    compute_detection(&sensor2);

    // Print results
    printf("Sensor 1 Detection Intervals:\n");
    print_intervals(&sensor1);
    printf("\nSensor 2 Detection Intervals:\n");
    print_intervals(&sensor2);

    return 0;
}