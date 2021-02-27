#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int s;

bool binary(long long q[], int n, int begin) {
	int mid, end = s-1;
	bool achou = false;
	while(begin <= end) {
		mid = (end+begin)/2;
		if(n > q[mid]) {
			achou = true;
			break;
		} else {
			end = mid-1;
		}
	}
	return achou;
}

int guerra(long long n[], long long q[]) {
	
	int maior = s-1, count = 0, j=0;
	for(int i = 0; i < s;i++) {
		if(binary(q, n[i], j)) {
			j++;
		}
	}
	return j;
}

int main() {
	cin >> s;
	long long n[s];
	long long q[s];
	
	for(int i=0;i<s;i++) {
		cin >> q[i];
	}
	for(int i=0;i<s;i++) {
		cin >> n[i];
	}
	
	sort(q, q+s);
	sort(n, n+s);
	cout << guerra(n, q) << "\n";
	
	return 0;
}