#include "main.h"

#define DATA_SIZE 20
#define ADJACENT  3

int main(void)
{
    float plot_data[DATA_SIZE];
    float init_data = 0;
    uint16_t count = 0;

    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        if(count < ADJACENT)
        {
            plot_data[i] = init_data;
            count++;
        }
        else
        {
            count = 1;
            init_data++;
            plot_data[i] = init_data;
        }
    }

    printf("Data initialization\n\n");
    print(plot_data);
    smoothing(plot_data, DATA_SIZE, ADJACENT);
    printf("\nData smoothing\n\n");
    print(plot_data);
}

void print(float *data)
{
    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        printf("data[%d] = %f\n", i, *(data + i));
    }
}