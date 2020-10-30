#include <stdio.h>

int main() {
	int money, money2, cem, cinq, vint, dez, cinc, dois, um;
	scanf("%d", &money);
	money2 = money;
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
	printf("%d\n", money2);
	printf("%d nota(s) de R$ 100,00\n", cem);
	printf("%d nota(s) de R$ 50,00\n", cinq);
	printf("%d nota(s) de R$ 20,00\n", vint);
	printf("%d nota(s) de R$ 10,00\n", dez);
	printf("%d nota(s) de R$ 5,00\n", cinc);
	printf("%d nota(s) de R$ 2,00\n", dois);
	printf("%d nota(s) de R$ 1,00\n", um);
	return 0;
}