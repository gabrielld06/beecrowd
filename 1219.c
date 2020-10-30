#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, p, aCir, aTri, aCirG, rMenor, rMaior, aMaior, aMenor;
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
		p = (a+b+c)/2;
		aTri = sqrt(p*(p-a)*(p-b)*(p-c));
		rMenor = (aTri/(p));
		rMaior = (a*b*c)/(aTri*4);
		aMaior = M_PI*rMaior*rMaior;
		aMenor = M_PI*rMenor*rMenor;
		aMaior = aMaior-aTri;
		aTri = aTri - aMenor;
		printf("%.4lf %.4lf %.4lf\n", aMaior, aTri, aMenor);
	}
	return 0;
}