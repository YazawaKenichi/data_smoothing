#include "main.h"

#define DATA_SIZE 100

void main(void)
{
    float plot_data[DATA_SIZE] = {0};

    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        plot_data[i] = (float)i;
    }

    smoothing(plot_data, 2, DATA_SIZE);
    print()
}

void print(float *data)
{
    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        printf("plot = %f", *(data + i));
    }
}