#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int n, i, j, k;
	char string[100000], saida[100000];
	cin >> n;
	for(i=0;i<n;i++){
		k=0;
		cin >> string;
		for(j=0;j<strlen(string);j++) {
			if(string[j] >= 96 && string[j] <= 122) {
				saida[k] = string[j];
				k++;
			}
			saida[k] = '\0';
		}
		for(j=strlen(saida)-1;j>=0;j--)
			printf("%c", saida[j]);
		printf("\n");
	}
	return 0;
}