#include <iostream>

using namespace std;

int fib(int n, int *num) {
	*num+=1;
	if(n==0) return 0;
	else if(n==1) return 1;
	else return fib(n-1, num) + fib(n-2, num);
}

int main() {
	int n, f, res, num;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> f;
		num = 0;
		res = fib(f, &num);
		cout << "fib(" << f << ") = " << num-1 << " calls = " << res << endl; 
	}
}