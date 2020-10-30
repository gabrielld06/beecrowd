#include <stdio.h>

int main() {
	int cem, cinq, vint, dez, cinc, dois, um, cinqc, vintc, dezc, cincc, umc;
	double money; 
	scanf("%lf", &money);
	for (cem=0;money>=100;cem++){
		money = money-100;
	}
	for (cinq=0;money>=50;cinq++){
		money = money-50;
	}
	for (vint=0;money>=20;vint++){
		money = money-20;
	}
	for (dez=0;money>=10;dez++){
		money = money-10;
	}
	for (cinc=0;money>=5;cinc++){
		money = money-5;
	}
	for (dois=0;money>=2;dois++){
		money = money-2;
	}
	for (um=0;money>=1;um++){
		money = money-1;
	}
	money = money*100;
	for (cinqc=0;money>=50;cinqc++){
		money = money-50;
	}
	for (vintc=0;money>=25;vintc++){
		money = money-25;
	}
	for (dezc=0;money>=10;dezc++){
		money = money-10;
	}
	for (cincc=0;money>=5;cincc++){
		money = money-5;
	}
	for (umc=0;money>=1;umc++){
		money = money-1;
	}
	printf("NOTAS:\n");
	printf("%d nota(s) de R$ 100.00\n", cem);
	printf("%d nota(s) de R$ 50.00\n", cinq);
	printf("%d nota(s) de R$ 20.00\n", vint);
	printf("%d nota(s) de R$ 10.00\n", dez);
	printf("%d nota(s) de R$ 5.00\n", cinc);
	printf("%d nota(s) de R$ 2.00\n", dois);
	printf("MOEDAS:\n");
	printf("%d moeda(s) de R$ 1.00\n", um);
	printf("%d moeda(s) de R$ 0.50\n", cinqc);
	printf("%d moeda(s) de R$ 0.25\n", vintc);
	printf("%d moeda(s) de R$ 0.10\n", dezc);
	printf("%d moeda(s) de R$ 0.05\n", cincc);
	printf("%d moeda(s) de R$ 0.01\n", umc);
	return 0;
}