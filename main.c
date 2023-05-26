#include "main.h"

#define DATA_SIZE 100

int main(void)
{
    float plot_data[DATA_SIZE] = {0};

    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        plot_data[i] = (float)i;
    }

    print(plot_data);
    smoothing(plot_data, 3, DATA_SIZE);
    printf("\nSmoothing\n\n");
    print(plot_data);
}

void print(float *data)
{
    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        printf("plot = %f\n", *(data + i));
    }
}