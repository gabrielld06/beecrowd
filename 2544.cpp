#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	while(cin >> n)
		cout << floor(log2(n)) << endl;
	return 0;
}