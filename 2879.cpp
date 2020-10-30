#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {
	int n, i;
	cin >> n;
	int porta = 0, ganhou = 0;
	for(i=0;i<n;i++) {
		cin >> porta;
		if(porta == 3 || porta == 2)
			ganhou++;
	}
	cout << ganhou << "\n";
	return 0;
}
