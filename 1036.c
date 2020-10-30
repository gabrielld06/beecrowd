#include <stdio.h>
#include <math.h>

int main(){
	float a = 0, b = 0, c = 0, delta = 0, raiz= 0, r1 = 0, r2 = 0;
	scanf("%f %f %f", &a, &b, &c);
	delta = (b*b)-(4.0*a*c);
	if (a!=0 && delta>=0) {
		raiz = sqrt(delta);
	    r1 = (-b+raiz)/(2.0*a);
	    r2 = (-b-raiz)/(2.0*a);
		printf("R1 = %.5f\n", r1);
		printf("R2 = %.5f\n", r2);
	}
	else {
	    printf("Impossivel calcular\n");
	}
}