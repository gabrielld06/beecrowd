#include <stdio.h>

int main() {
	int x1, x2, y1, y2, i, fon;
	x1 = 1;
	x2 = 1;
	y1 = 1;
	y2 = 1;
	while (x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0) {
		fon = 0;
		scanf("%d", &x1);
		scanf("%d", &y1);
		scanf("%d", &x2);
		scanf("%d", &y2);
		if (x1 == 0 && x2 == 0 && y1 == 0 && y2 ==0 ){
			fon = 3;
		} else if (x1 == x2 && y1 == y2) {
			printf("0\n");
			fon = 3;
		} else if (x1 == x2 || y1 == y2) {
			printf("1\n");
			fon = 3;
		} else {
			for(i=1;i<=8;i++) {
				if((x2 == x1+i || x2 == x1-i) && (y2 == y1-i || y2 == y1-i)) {
					printf("1\n");
					i=8;
					fon = 3;
				} else if((x1 == x2+i || x1 == x2-i) && (y1 == y2-i || y1 == y2-i)) {
					printf("1\n");
					i=8;
					fon = 3;
				}
			}
		}
		if (fon != 3) {
			printf("2\n");
		}
	}
	return 0;
}