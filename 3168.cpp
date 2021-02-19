#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double binomio(double n, double k) {
	double fat=1, fat1=1;
	for(int i = n;i > k;i--) fat *= i;
	for(int i = n-k;i > 1;i--) fat1 *= i;
	return fat / fat1;
}

int main() {
	int t;
	double n, k, p;
	cin >> t;
	for(int i=0;i<t;i++) {
		cin >> n >> k >> p;
		p /= 100;
		cout << "A chance de Basy acertar o numero no dia " << i+1 << " eh " << fixed
			<< setprecision(2) << binomio(n, k) * pow(p, k) * pow((1-p), n-k) * 100 << "%\n";
	}
	return 0;
}