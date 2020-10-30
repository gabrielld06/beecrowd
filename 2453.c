#include <stdio.h>
#include <string.h>

int main() {
	int i, j;
	char string[1000];
	scanf("%[^\n]s", string);
	for(i=0;string[i]!='\0';i++) {
		if(string[i]=='p') {
			for(j=i;j<strlen(string);j++) {
				string[j] = string[j+1];
			}
		}
	}
	printf("%s\n", string);
	return 0;
}

######################3
#include <stdio.h>
#include <string.h>

int main() {
	int i, j;
	char string[1000];
	scanf("%[^\n]s", string);
	for(i=0;i<strlen(string);i++) {
		if(string[i]=='p') {
			for(j=i;j<strlen(string);j++) {
				string[j] = string[j+1];
			}
		}
	}
	printf("%s\n", string);
	return 0;
}