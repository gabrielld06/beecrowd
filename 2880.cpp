#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
	char crib[10001], msg[10001];
	cin >> crib >> msg;
	int i, j, con=0, n=0;
	for(i=0;i<strlen(crib)-strlen(msg)+1;i++) {
		con=0;
		for(j=0;j<strlen(msg);j++) {
			if(msg[j] == crib[j+i]) {
				j=strlen(msg);
				con = 1;
			}
		}
		if(!con)
			n++;
	}
	cout << n << "\n";
	return 0;
}
