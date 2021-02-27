#include <iostream>
#include <cmath>

using namespace std;

long long int fat(long long int n) {
	int count = 0;
	if(n % 2 == 0) {
		count++;
		n /= 2;
	}
	while(n % 2 == 0) {
		n /= 2;
	}
	for(long long int i=3; i<=sqrt(n);i+=2) {
		if(n % i == 0) {
			count++;
			n /= i;
		}
		while(n % i == 0) {
			n /= i;
		}
	}
	if(n > 1) {
		count++;
	}
	return count;
}

long long dp(long long n) {
	if(n == 2) return 1;
	return 2*dp(n-1) + n-1;
}

int main() {
	long long n;
	cin >> n;
	long long ft = fat(n);
	if(ft <= 1)
		cout << 0 << endl;
	else
		cout << dp(ft) << endl;
	
	return 0;
}