#include <iostream>

using namespace std;

/* int fib(int n, int *num) {
	*num+=1;
	if(n==0) 
		return 0;
	else if(n==1) 
		return 1;
	else 
		return fib(n-1, num) + fib(n-2, num);
} */

int memo[40], memocall[40];

int chamadas(int n) {
	int ans;
	if(memocall[n] == -1) {
		if(n==0) 
			ans = 1;
		else if(n==1) 
			ans = 1;
		else 
			ans = 1 + chamadas(n-1) + chamadas(n-2);
		memocall[n] = ans;
	}
	return memocall[n];
}

int fib(int n) {
	int ans;
	if(memo[n]==-1) {
		if(n==0) 
			ans = 0;
		else if(n==1) 
			ans = 1;
		else 
			ans = fib(n-1) + fib(n-2);
		memo[n] = ans;
	}
	return memo[n];
}

int main() {
	int n, f, res, num;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> f;
		for(int i=0;i<=f;i++) {
			memo[i] = -1;
			memocall[i] = -1;
		}
		//num = 0;
		//res = fib(f, &num);
		//cout << "fib(" << f << ") = " << num-1 << " calls = " << res << endl; 
		cout << "fib(" << f << ") = " << chamadas(f)-1 << " calls = " << fib(f) << endl; 
	}
}