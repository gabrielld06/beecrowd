#include <iostream>
#include <vector>

using namespace std;

int verified=0;
vector<int> verify(101, -1);

int nao_eh_guloso(int n, int max, int boolean[101][101]) {
	int ans = 0;
	if(verified == max) {
		return 1;
	} else {
		if(verify[n] == -1) {
			verify[n]=1;
			verified++;
			if(verified == max) {
				return 1;
			}
		}
		for(int i=0;i<max and boolean[i][n]!=-1;i++) {
			if(verify[boolean[i][n]] == -1) {
				ans = nao_eh_guloso(boolean[i][n], max, boolean);
				if(ans == 1) return 1;
			}
		}
	}
	return 0;
}

int main() {
	int n, l, x, y, k;
	cin >> n >> l;
	int boolean[101][101];
	for(int i=0;i<101;i++)
		for(int j=0;j<101;j++) boolean[i][j] = -1;
	vector<int> indices(n, 0);
	for(int i=0;i<l;i++) {
		cin >> x >> y;
		boolean[indices[x-1]++][x-1] = y-1;
		boolean[indices[y-1]++][y-1] = x-1;
	}
	cout << (nao_eh_guloso(n-1, n, boolean) == 1 ? "COMPLETO" : "INCOMPLETO") << endl;
}