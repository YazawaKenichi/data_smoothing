#include "main.h"
#include <stdlib.h>
#include <math.h>
#include "flash.h"

int main(int argc, char *argv[])
{
    //! argv 1 : adj, 2 : path
    smooth(atoi(argv[1]), argv[2]);
    return 0;
}

int smooth(uint8_t adj, char *path)
{
    uint8_t data_size = (uint8_t) ((double) sizeof(normalx) / (double) sizeof(int));
    int* ptrx = normalx;
    int* ptry = normaly;
    int *befx = malloc(data_size * sizeof(int));
    int *aftx = malloc(data_size * sizeof(int));
    int *befy = malloc(data_size * sizeof(int));
    int *afty = malloc(data_size * sizeof(int));

    //! 出力用データ保存
    for(int i = 0; i < data_size; i++)
    {
        *(befx + i) = *(ptrx + i);
        *(befy + i) = *(ptrx + i);
    }

    //! 平滑化
    printf("Smoothing X\r\n");
    smoothing(ptrx, data_size, adj, 0x01);
    printf("Smoothing Y\r\n");
    smoothing(ptry, data_size, adj, 0x01);

    //! 出力用データ保存
    for(int i = 0; i < data_size; i++)
    {
        *(aftx + i) = *(ptrx + i);
        *(afty + i) = *(ptry + i);
    }

    write(path, aftx, afty, data_size);
}

void write(char *path, int *x, int *y, uint8_t size)
{
    FILE *f = NULL;
    f = fopen(path, "w");
    for(uint16_t i = 0; i < size; i++)
    {
        fprintf(f, "%d, %d\r\n", *(x + i), *(y + i));
    }
    fclose(f);
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

