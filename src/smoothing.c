#include "smoothing.h"

#include <stdio.h>
#include <stdlib.h>

void smoothing(int *data, uint16_t size, uint8_t adj)
{
    uint8_t from;
    uint16_t to;
    //! i の移動範囲 from <= i < to
    from = 0 + adj;
    to = size - adj - 1;
    int *buf = malloc(from * sizeof(int));
    for (uint16_t i = from; i < to; i++)
    {
        int sum = 0;
        uint16_t j;
        float ave;
        //! バッファの部分の加算
        for (j = 0; j < from; j++)
        {
            sum += *(buf + j);
        }
        //! 元配列の部分の加算
        for (j = i; j <= i + adj; j++)
        {
            sum += *(data + j);
        }
        //! 平均値の算出
        ave = sum / (2 * adj + 1);
        //! 
        for (j = 0; j + 1 < from; j++)
        {
            buf[j] = buf[j + 1];
        }
        buf[j] = *(data + i);
        *(data + i) = (int) ave;
    }
    free(buf);
}

