#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// just a faster way to do it

int main() {
	int n, sVisited = 0, star, stolen = 0, back = 0, i;
	bool stop = false;
	ll soma = 0;

	cin >> n;
	
	for(i = 0;i < n and not stop;i++) {
		scanf("%d", &star);
		//cin >> star;
		soma += star;
		if(star % 2) { 
			if(star > 0)
				stolen++;
			if(star > 1)
				back++;
			sVisited++;
		} else {
			if(star > 0)
				stolen++;
			sVisited++;
			// break this loop so we can stop wasting time on those verifications
			stop = true;
		}
	}
	// finish reading the input
	for(;i < n;i++) {
		scanf("%d", &star);
		//cin >> star;
		soma += star;
	}
	
	if(stop) stolen += back;
	printf("%d %lld\n", sVisited, (soma - stolen));
	//cout << sVisited << " " << (soma - stolen) << endl;
	
	return 0;
}

