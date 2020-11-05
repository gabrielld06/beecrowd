#include <iostream>
#include <string>

using namespace std;

int memo[1002][1002];

int max(int x, int y) {
	if(x>y) return x;
	else return y;
}

int subseq(string a, string b, int n, int m) {
	int ans;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0 or j==0)
				ans = 0;
			else if(a[i-1]==b[j-1]) {
				ans = 1 + memo[i-1][j-1];
			} else if(a[i-1]!=b[j-1]) {
				ans = max(memo[i-1][j], memo[i][j-1]);
			}
			memo[i][j] = ans;
		}
	}
	return memo[n][m];
}

int main() {
	string a, b;
	cin >> a >> b;
	int len_a = a.length(), len_b = b.length();

	cout << len_a + len_b - subseq(a, b, len_a, len_b) << endl;
	return 0;
}