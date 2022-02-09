#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 0;
	string str;
	map<string, bool> mp;
		
	while(cin >> str) {
		if(!mp[str]) {
			mp[str] = true;
			n++;
		}
	}
	cout << n << endl;

	return 0;
}