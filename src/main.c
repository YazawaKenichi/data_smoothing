#include "main.h"
#include <stdlib.h>
#include <math.h>

#define DATA_SIZE 20

int main(int argc, char *argv[])
{
    int plot_data[DATA_SIZE];
    int bef[DATA_SIZE];
    int aft[DATA_SIZE];
    float init_data = 0;
    uint16_t count = 0;
    uint8_t adj = atoi(argv[1]);
    uint8_t bias = 100;

    //! センサのデータ配列を作成
    for(uint16_t i = 0; i < DATA_SIZE; i++)
    {
        if(count < adj)
        {
            plot_data[i] = rand_normal(init_data * bias, 16);
            count++;
        }
        else
        {
            count = 1;
            init_data++;
            plot_data[i] = rand_normal(init_data * bias, 16);
        }
    }

    //! 出力用データ保存
    for(int i = 0; i < DATA_SIZE; i++)
    {
        bef[i] = plot_data[i];
    }

    //! 平滑化
    smoothing(plot_data, DATA_SIZE, adj);

    //! 出力用データ保存
    for(int i = 0; i < DATA_SIZE; i++)
    {
        aft[i] = plot_data[i];
    }

    print(bef, aft);
}

void print(int *bef, int *aft)
{
    for(uint16_t i = 0; i < DATA_SIZE; i++)
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

