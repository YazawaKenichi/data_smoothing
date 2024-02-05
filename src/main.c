#include "main.h"
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    float init_data = 0;
    uint16_t count = 0;
    uint8_t data_size = atoi(argv[1]);
    uint8_t adj = atoi(argv[2]);
    uint8_t bias = 100;
    int *plot_data = malloc(data_size * sizeof(int));
    int *bef = malloc(data_size * sizeof(int));
    int *aft = malloc(data_size * sizeof(int));

    //! センサのデータ配列を作成
    for(uint16_t i = 0; i < data_size; i++)
    {
        if(count < adj)
        {
            *(plot_data + i) = rand_normal(init_data * bias, 16);
            count++;
        }
        else
        {
            count = 1;
            init_data++;
            *(plot_data + i) = rand_normal(init_data * bias, 16);
        }
    }

    //! 出力用データ保存
    for(int i = 0; i < data_size; i++)
    {
        *(bef + i) = *(plot_data + i);
    }

    //! 平滑化
    smoothing(plot_data, data_size, adj);

    //! 出力用データ保存
    for(int i = 0; i < data_size; i++)
    {
        *(aft + i) = *(plot_data + i);
    }

    print(bef, aft, data_size);
}

void print(int *bef, int *aft, uint8_t size)
{
    for(uint16_t i = 0; i < size; i++)
    {
        printf("%d, %d\n", *(bef + i), *(aft + i));
    }
}

double Uniform( void )
{
    return ((double) rand() + 1.0) / ((double) RAND_MAX + 2.0);
}

double rand_normal( double mu, double sigma )
{
    double z = sqrt( -2.0 * log(Uniform())) * sin(2.0 * M_PI * Uniform());
    return mu + sigma * z;
}

