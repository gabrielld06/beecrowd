#include <iostream>

using namespace std;

int main() {
	int b, g, resto;
	
	cin >> b >> g;
	resto = g/2 - b;
	if(resto <= 0) {
		cout << "Amelia tem todas bolinhas!\n";
	} else {
		cout << "Faltam " << resto << " bolinha(s)\n";
	}
	return 0;
}