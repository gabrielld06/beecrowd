#include <stdio.h>

int main() {
	int func[3],i;
	for (i=0;i<3;i++) {
		scanf("%d", &func[i]);
	}
	if (((func[0]*2+func[1])*2) < ((func[0]+func[2])*2) && ((func[0]*2+func[1])*2) < ((func[1]+func[2]*2)*2)) {
		printf("%d\n", (func[0]*2+func[1])*2);
	} else if (((func[1]+func[2]*2)*2) < ((func[0]+func[2])*2) && ((func[1]+func[2]*2)*2) < ((func[0]*2+func[1])*2)) {
		printf("%d\n", (func[1]+func[2]*2)*2);
	} else if (((func[0]+func[2])*2) < ((func[1]+func[2]*2)*2) && ((func[0]+func[2])*2) < ((func[0]*2+func[1])*2)) {
		printf("%d\n", (func[0]+func[2])*2);;
	} else {
		if (func[0] > func[1] && func[0] > func[2]) {
			printf("%d\n", (func[1]+func[2]*2)*2);
		} else if (func[1] > func[0] && func[1] > func[2]) {
			printf("%d\n", (func[0]+func[2])*2);
		} else if (func[2] > func[0] && func[2] > func[1]) {
			printf("%d\n", (func[0]*2+func[1])*2);
		} else {
			printf("%d\n", (func[0]+func[2])*2);	
		}
	}
	return 0;
}