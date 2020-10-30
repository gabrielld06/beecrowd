#include <iostream>

using namespace std;
/*
int josephus(int n, int k) {
	if(n == 1) return 0;
	return ((josephus(n-1, k)+k) % n);
}*/

int josephus(int n, int k) { //iterativo
	int memo[n], i;
	memo[0] = 0;
	for(i=1;i<=n;i++) memo[i] = (memo[i-1]+k) % i;
	return memo[n];
}

int main() {
	int nc, n, k, i;
	
	cin >> nc;
	for(i=0;i<nc;i++) {
		cin >> n >> k;
		
		cout << "Case " << i+1 << ": " << josephus(n, k) + 1 << endl;
	}
}