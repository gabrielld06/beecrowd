#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ll n, pairs[10001], maior, menor, input, v;
	cin >> n;
	while(n != 0) {		
		vector<ll> gifts;
		for(ll i = 0; i < 2*n; i++) {
			cin >> input;
			gifts.push_back(input);
		}
		
		sort(gifts.begin(), gifts.end());

		maior = -1, menor = LLONG_MAX;
		for(ll i = 0; i < n; i++) {
			v = gifts[i] + gifts[2*n-i-1];
			maior = max(maior, v);
			menor = min(menor, v);
		}
		
		cout << maior << " " << menor << endl;
		
		cin >> n;
	}
	
	return 0;
}