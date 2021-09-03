#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class star {
	public:
	int c;
	bool visited = false;
};

int main() {
	int n, sVisited = 0;
	ll soma = 0;
	star stars[1000001];

	cin >> n;
	
	for(int i = 0;i < n;i++) {
		cin >> stars[i].c;
		soma += stars[i].c;
	}
	int i = 0, to;
	while(true) {
		if(stars[i].c % 2) {
			to = i + 1;
		} else {
			to = i - 1;
		}
		if(not stars[i].visited) {
			sVisited++;
			stars[i].visited = true;
		}
		if(stars[i].c > 0) {
			stars[i].c--;
			soma--;
		}
		if(to == n or to < 0) {
			break;
		}
		i = to;
	}
	
	cout << sVisited << " " << soma << endl;
	
	return 0;
}

