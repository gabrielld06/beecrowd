#include <bits/stdc++.h>

#define INF 2147483647

using namespace std;

int value[1000001];

int iterative(int m, vector<int> vet) {
	value[0] = 0;
	for(int x = 1; x <= m;x++) {
		value[x] = INF;
		for(auto c : vet) {
			if(x-c >= 0) {
				value[x] = min(value[x], value[x-c]+1);
			}
		}
	}
	return value[m];
}

int main() {
	int n, t, m, input;
	
	cin >> n;
	while(n--) {
		cin >> t >> m;
		vector<int> vet;
		while(t--) {
			cin >> input;
			vet.push_back(input);
			//sort(vet.begin(), vet.end());
		}
		cout << iterative(m, vet) << endl;
	}
	return 0;
}