#include <stdio.h>
#include <math.h>

#define N 13

void main(){

	int i = 0;

	double Teff[N];
	double error_Teff[N];
	double logL_L0[N];
	double error_logL_L0[N];
	double Mk[N];
	double error_Mk[N];
	double Mbol[N];
	double error_Mbol[N];
	double M_M0[N];
	double error_M_M0[N];

	FILE *file = NULL;
	FILE *file2 = NULL;

	file = fopen("davies.dat","r");
	file2 = fopen("data_davies.dat","w");	

	while(fscanf(file,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",&Teff[i],&error_Teff[i],&logL_L0[i],&error_logL_L0[i],&Mk[i],&error_Mk[i]) != EOF){
		Mbol[i] = 4.8 - 2.5*logL_L0[i];
		error_Mbol[i] = 2.5*error_logL_L0[i];
		M_M0[i] = pow(10,0.5-0.1*Mbol[i]);
		error_M_M0[i] = 0.1*log(10)*M_M0[i]*error_Mbol[i];
		fprintf(file2,"%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",log10(Teff[i]),log10(error_Teff[i])/(Teff[i]*log(10)),logL_L0[i],error_logL_L0[i],Mbol[i],error_Mbol[i],M_M0[i],error_M_M0[i]);
		i++;
	}

	fclose(file);
	fclose(file2);
}
