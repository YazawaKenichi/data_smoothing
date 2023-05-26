#include "main.h"

#define DATA_SIZE 20
#define ADJACENT  3

int main(void)
{
    float plot_data[DATA_SIZE];
    uint16_t i;

    for(i = 0; i < ADJACENT; i++) plot_data[i] = 5;
    for(i = ADJACENT; i < DATA_SIZE-ADJACENT; i++) plot_data[i] = 2;
    for(i = DATA_SIZE-ADJACENT; i < DATA_SIZE; i++) plot_data[i] = 6;

    print(plot_data);
    smoothing(plot_data, DATA_SIZE, ADJACENT);
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