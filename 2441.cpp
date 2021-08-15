#include <bits/stdc++.h>

using namespace std;

int main() {
	int resp = 0;
	vector<int> windows(3, 0);
	
	cin >> windows[0] >> windows[1] >> windows[2];
	
	sort(windows.begin(), windows.end());
	
	if(windows[0] != 0) {
		resp += windows[0] * 100;
	}
	if(windows[0] + 200 < windows[1]) {
		resp += (windows[1] - (windows[0] + 200)) * 100;
	}
	if(windows[1] + 200 < windows[2]) {
		resp += (windows[2] - (windows[1] + 200)) * 100;
	}
	if(windows[2] + 200 < 600) {
		resp += (400 - windows[2]) * 100;
	}
	
	cout << resp << endl;
	
	return 0;
}