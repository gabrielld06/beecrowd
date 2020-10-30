#include <stdio.h>
#include <string.h>

int main() {
	int n, i, str;
	char num[20];
	scanf("%d", &n);
	for (i=0;i<n;i++) {
		scanf("%s", num);
		str = strlen(num);
		if (strlen(num)==3) {
			if (num[0] == 'o' && num[1] == 'n' || num[0] == 'o' && num[2] == 'e' || num[1] == 'n' && num[2] == 'e') {
				printf("1\n");
			} else {
				printf("2\n");
			}
		} else if (strlen(num)==5) {
			printf("3\n");
		}
	}
	return 0;
}