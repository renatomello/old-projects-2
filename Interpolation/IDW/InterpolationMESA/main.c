#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Grid.h"

#define Boltzmann (5.67*pow(10,-5))	// [Boltzmann] = erg cm⁻² s⁻¹ K⁻⁴

#define R0 (6.96*pow(10,10))		// [R0] = cm
#define M0 (1.99*pow(10,33))		// [M0] = g
#define T0 (5800.)			// [T0] = K

int main()
{
    LeituraGrid();

    return 0;
}
