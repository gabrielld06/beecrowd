#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<int> aux(201, -1);
vector<vector<int>> memo(201, aux);

int lcs(string s1, string s2, int i, int j) {
	int ans;
	if(memo[i][j] == -1) {
		if(i == 0 or j == 0) {
			ans = 0;
		} else if(s1[i-1] == s2[j-1]) {
			ans = 1 + lcs(s1, s2, i-1, j-1);
		} else {
			ans = max(lcs(s1, s2, i-1, j), lcs(s1, s2, i, j-1));
		}
		memo[i][j] = ans;
	}
	return memo[i][j];
}

int main() {
	string a, b;
	char aux;
	cin >> a >> b;
	for(int i = 0;i < a.length();i++) {
		if(islower(a[i])) {
			aux = toupper(a[i]);
			a = a.substr(0, i) + aux + aux + a.substr(i+1);
		}
	}
	for(int i = 0;i < b.length();i++) {
		if(islower(b[i])) {
			aux = toupper(b[i]);
			b = b.substr(0, i) + aux + aux + b.substr(i+1);
		}
	}

	cout << lcs(a, b, a.length(), b.length()) << endl;
	
	return 0;
}