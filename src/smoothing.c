#include "smoothing.h"

#include <stdio.h>
#include <stdlib.h>

void smoothing(int *data, uint16_t size, uint8_t adj, uint8_t ui)
{
    uint8_t from;
    uint16_t to;
    from = 0 + adj;
    to = size - adj;
    int *buf = malloc(from * sizeof(int));
    for(uint8_t j = 0; j < from; j++)
    {
        *(buf + j) = *(data + j);
    }
    for(uint16_t i = from; i < to; i++)
    {
        int sum = 0;
        uint16_t j;
        float ave;
        for(j = 0; j < from; j++)
        {
            sum += *(buf + j);
            if(ui)
            {
               printf("%d + ", *(buf + j));
            }
        }
        for(j = i; j <= i + adj; j++)
        {
            sum += *(data + j);
            if(ui)
            {
                printf("%d + ", *(data + j));
            }
        }
        ave = sum / (float) (2 * adj + 1);
        if(ui)
        {
            printf("= %d / %d = %f\r\n", sum, (2 * adj + 1), ave);
        }
        for(j = 0; j + 1 < from; j++)
        {
            *(buf + j) = *(buf + j + 1);
        }
        *(buf + j) = *(data + i);
        *(data + i) = (int) ave;
    }
    free(buf);
}

