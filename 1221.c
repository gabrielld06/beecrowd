#include <stdio.h>
#include <math.h>

int primo(int x) {
	int teste, i;
	if (x == 2) {
		return 1;
	} else if (x % 2 == 0) {
		return 0;
	} else {
		for (i=3;i <= sqrt(x);i+=2) {
			teste = x % i;
			if (teste == 0) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
	int num, caso, j;
	scanf("%d", &caso);
 	for (j=0;j<caso;j++) {
    	scanf("%d", &num);
    	if(primo(num)==1){
    		printf("Prime\n");
    	} else {
    		printf("Not Prime\n");
    	}
 	}
	return 0;
}

############
#include <stdio.h>
#include <math.h>

int main() {
 	long int num, i=0, j, teste, caso, primo;
 	scanf("%ld", &caso);
 	for (j=0;j<caso;j++) {
 		primo = 0;
 		scanf("%ld", &num);
 		if (num == 2) {
 			primo = 0;
 		} else if (num % 2 == 0 || num == 1) {
 			primo = 1;
 		} else {
 			for (i=3;i < sqrt(num);i+=2) {
		 		teste = num % i;
		 		if (teste == 0) {
		 			primo++;
		 		}
			}
 		}
 		if (primo > 0) {
 			printf("Not Prime\n");
 		} else if (primo == 0) {
 			printf("Prime\n");
 		}
	}
	return 0;
}
