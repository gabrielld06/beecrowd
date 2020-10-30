#include <iostream>

using namespace std;

int main() {
	int d, i, x, f;
	cin >> d >> i >> x >> f;
	if (d%2 == 0) {
		if ((f-d)%2 == 0) {
			cout << i << "\n";
		} else {
			cout << i - x << "\n";
		}
	} else {
		if ((f-d)%2 == 0) {
			cout << i + x << "\n";
		} else {
			cout << i << "\n";
		}
	}
	return 0;
}