#include <bits/stdc++.h>
#define ALL(V) V.begin(), V.end()
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORIT(i, a) for (TI(a) i = a.begin(); i != a.end(); i++)
#define TI(X) __typeof((X).begin())
#define PRINT(X) cout << X << "\n"
#define READ(X) cin >> X
#define pb push_back
#define mp make_pair

const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, line[3], p, t;
	while(READ(n) and n) {
		p = 1, t = 0;
		for(int i = 0;i < n;i++) {
			cin >> line[0] >> line[1] >> line[2];
			
			if(line[p]) {
				if(p == 1) {
					t++;
					if(line[0]) {
						p = 2;
					} else {
						p = 0;
					}
				} else {
					if(line[1]) {
						t += 2;
						p = 2-p;
					} else {
						t++;
						p = 1;
					}
				}
			}
		}
		PRINT(t);
	}
	
	return 0;
}