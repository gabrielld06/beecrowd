#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int n, i, x1, y1, x2, y2, cima, baixo, simpli1, simpli2, mmdcima, mmdbaixo;
	char o1, o2[1], o3;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %c %d %c %d %c %d", &x1, &o1, &y1, &o2, &x2, &o3, &y2);
		if (strncmp (o2, "+", 1)==0) {
			cima = x1*y2+x2*y1;
			baixo = y1*y2;
			simpli1 = cima;
			simpli2 = baixo;
		}
		else if (strncmp (o2, "-", 1)==0) {
			cima = x1*y2-x2*y1;
			baixo = y1*y2;
			simpli1 = cima;
			simpli2 = baixo;
		}
		else if (strncmp (o2, "*", 1)==0) {
			cima = x1*x2;
			baixo = y1*y2;
			simpli1 = cima;
			simpli2 = baixo;
		}
		else if (strncmp (o2, "/", 1)==0) {
			cima = x1*y2;
			baixo = x2*y1;
			simpli1 = cima;
			simpli2 = baixo;
		}
		while (abs(simpli1)!=abs(simpli2) && (cima!=0)) {
				if (abs(simpli1) > abs(simpli2 )){
					simpli1 = abs(simpli1) - abs(simpli2);
				}
				else if (abs(simpli2) > abs(simpli1)) {
					simpli2 = abs(simpli2) - abs(simpli1);
				}
			}
		if (cima!=0){
			simpli1 = cima/abs(simpli1);
			simpli2 = baixo/abs(simpli2);
			printf("%d/%d = %d/%d\n", cima, baixo, simpli1, simpli2);
		}else{
			printf("%d/%d = 0/1\n", cima, baixo);
		}
	}
	return 0;
}

######################################################################

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	int n, i, x1, y1, x2, y2, cima, baixo, simpli1, simpli2, mmdcima, mmdbaixo;
	char o1, o2[1], o3;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d %c %d %c %d %c %d", &x1, &o1, &y1, &o2, &x2, &o3, &y2);
		if (strncmp (o2, "+", 1)==0) {
			cima = x1*y2+x2*y1;
			baixo = y1*y2;
			simpli1 = cima;
			simpli2 = baixo;
			while (abs(simpli1)!=abs(simpli2) && (cima!=0)) {
				if (abs(simpli1) > abs(simpli2 )){
					simpli1 = abs(simpli1) - abs(simpli2);
				}
				else if (abs(simpli2) > abs(simpli1)) {
					simpli2 = abs(simpli2) - abs(simpli1);
				}
			}
		}
		else if (strncmp (o2, "-", 1)==0) {
			cima = x1*y2-x2*y1;
			baixo = y1*y2;
			simpli1 = cima;
			simpli2 = baixo;
			while (abs(simpli1)!=abs(simpli2) && (cima != 0)) {
				if (abs(simpli1) > abs(simpli2 )){
					simpli1 = abs(simpli1) - abs(simpli2);
				}
				else if (abs(simpli2) > abs(simpli1)) {
					simpli2 = abs(simpli2) - abs(simpli1);
				}
			}
		}
		else if (strncmp (o2, "*", 1)==0) {
			cima = x1*x2;
			baixo = y1*y2;
			simpli1 = cima;
			simpli2 = baixo;
			while (abs(simpli1)!=abs(simpli2) && (cima!=0)) {
				if (abs(simpli1) > abs(simpli2 )){
					simpli1 = abs(simpli1) - abs(simpli2);
				}
				else if (abs(simpli2) > abs(simpli1)) {
					simpli2 = abs(simpli2) - abs(simpli1);
				}
			}
		}
		else if (strncmp (o2, "/", 1)==0) {
			cima = x1*y2;
			baixo = x2*y1;
			simpli1 = cima;
			simpli2 = baixo;
			while (abs(simpli1)!=abs(simpli2) && (cima!=0)) {
				if (abs(simpli1) > abs(simpli2 )){
					simpli1 = abs(simpli1) - abs(simpli2);
				}
				else if (abs(simpli2) > abs(simpli1)) {
					simpli2 = abs(simpli2) - abs(simpli1);
				}
			}
		}
		if (cima!=0){
			simpli1 = cima/abs(simpli1);
			simpli2 = baixo/abs(simpli2);
			printf("%d/%d = %d/%d\n", cima, baixo, simpli1, simpli2);
		}else{
			printf("%d/%d = 0/1\n", cima, baixo);
		}
	}
	return 0;
}