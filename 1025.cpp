#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q, w, find[10001], testCase = 1;
	vector<int>::iterator pos;
	cin >> n >> q;
	
	while(n != 0 and q != 0) {
		vector<int> marbles;
		
		for(int i = 0; i < n; i++) {
			cin >> w;
			marbles.push_back(w);
		}
		
		for(int i = 0; i < q; i++) {
			cin >> find[i];
		}
		
		cout << "CASE# " << testCase++ << ":" << endl;
		
		sort(marbles.begin(), marbles.end());
		
		for(int f = 0; f < q;f++) {
			pos = lower_bound(marbles.begin(), marbles.end(), find[f]);

			if(marbles[pos - marbles.begin()] == find[f]) {
				cout << find[f] << " found at " << pos - marbles.begin() + 1 << endl;
			} else {
				cout << find[f] << " not found" << endl;
			}
		}
		cin >> n >> q;
	}
	
	return 0;
}