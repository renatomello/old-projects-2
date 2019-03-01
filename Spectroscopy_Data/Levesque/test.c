#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67384*pow(10,-11)
#define R0 (double)(6.96*pow(10,8))		// [R0] = m
#define M0 (double)(1.99*pow(10,30))		// [M0] = kg

void main(){
	double erroMbol = 0.3;
	double Mbol[58];
	double M[58];

	FILE *fentrada = fopen("mbol.dat","r");
	if (fentrada == NULL) printf("Nao foi possivel abrir o arquivo %s\n","mbol.dat");
	int i=0;
	while (fscanf(fentrada,"%lf",&Mbol[i]) != EOF)	i++;
	fclose(fentrada);

	fentrada = fopen("mass.dat","w");

	for(i=0;i<58;i++){
		M[i] = pow(10,0.5 - 0.1*Mbol[i]);
		fprintf(fentrada,"%lf	%lf\n",Mbol[i],M[i]);
	}

	fclose(fentrada);

}
