#include "plot_smoothing.h"

void smoothing(float *data_addr, uint16_t num_of_adjacent, uint16_t data_size)
{
    float cp_data[data_size] = {0};
    uint16_t i, j;
    int16_t min, max;
    float avg;
    double sum;

    for(i = 0; i < size; i++)
    {
        sum = 0;
        min = i - num_of_adjacent;
        max = i + num_of_adjacent;
        for(j = min; j <= max; j++)
        {
            if(j < 0 || j >= size) continue;
            sum += *(data_addr + j);
        }
        avg = (float)sum / (num_of_adjacent * 2 + 1);
        cp_data[i] = avg;
    }

    for(i = 0; i < size; i++)
    {
        *(data_addr + i) = cp_data[i];
    }
}