#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll countSetBits(ll x) {
    ll count = 0;
    while (x) {
        x &= (x-1);
        count++;
    }
    return count;
}

int main() {
	
	ll n;
	cin >> n;
	cout << fixed << setprecision(0) << pow(2, countSetBits(n)) << "\n";
	return 0;
}