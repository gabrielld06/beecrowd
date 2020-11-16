#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long t, n, n2, exp;
	cin >> t;
	for(int j=0;j<t;j++) {
		cin >> n;
		n2 = n;
		exp = 0;
		while(n % 2 == 0) {
			n /= 2;
			exp++;
		}
		if(exp % 2 == 1) n2 *= 2;
		for(int i=3; i<=sqrt(n);i+=2) {
			exp = 0;
			while(n % i == 0) {
				exp++;
				n /= i;
			}
			if(exp % 2 == 1) n2 *= i;
		}
		if(n > 1)
			n2 *= n;;
		cout << "Caso #" << j+1 << ": " << n2 << endl;
	}
	return 0;
}