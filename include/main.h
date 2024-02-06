#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "smoothing.h"

int smooth(uint8_t adj, char *path);
void write(char *path, int *x, int *y, uint8_t size);
double Uniform( void );
double rand_normal( double mu, double sigma );

#endif

