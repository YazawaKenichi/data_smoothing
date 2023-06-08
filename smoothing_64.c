// SPDX-FileCopyrightText: 2023 nacky823
// SPDX-License-Identifier: Apache-2.0
#include "smoothing.h"

/**
* This is a function that,
* given a data address,
* smoothes the data and saves it by overwriting.
*
* @param[out] data_addr The address of the first data element to be smoothed.
* @param[in] data_size The number of data points to be smoothed.
* @param[in] num_of_adjacent
*     The number of data points before and after a specific data point
*     that will be used for smoothing.
*/
void smoothing(float *data_addr, uint16_t data_size, uint16_t num_of_adjacent)
{
    float cp_data[data_size];
    uint16_t i, j, max;
    int16_t min;
    double sum;
    float avg;

    for(i = 0; i < data_size; i++) cp_data[i] = 0;

    for(i = 0; i < data_size; i++)
    {
        sum = 0;
        min = i - num_of_adjacent;
        max = i + num_of_adjacent;
        for(j = min; j <= max; j++)
        {
            if(j < 0 || j >= data_size) continue;
            sum += *(data_addr + j);
        }
        if(i < num_of_adjacent || i >= (data_size - num_of_adjacent))
        {
            cp_data[i] = *(data_addr + i);
            continue;
        }
        avg = (float)sum / (num_of_adjacent * 2 + 1);
        cp_data[i] = avg;
    }

    for(i = 0; i < data_size; i++)
    {
        *(data_addr + i) = cp_data[i];
    }
}