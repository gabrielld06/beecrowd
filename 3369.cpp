#include <iostream>
#include <vector>

using namespace std;

vector<string> sList;

int acro(string str, int count[]) {
	for(auto c : str) {
		if(not count[c-'A']) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	int n, count[26] = {0};
	string str;
	
	cin >> n;
	
	for(int i = 0;i < n;i++) {
		cin >> str;
		count[str[0]-'A']++;
		sList.push_back(str);
	}
	
	for(auto s : sList) {
		if(acro(s, count)) {
			cout << 'Y' << endl;
			return 0;
		}
	}
	
	cout << 'N' << endl;
	
	return 0;
}