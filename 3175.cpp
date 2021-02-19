#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, g[10001], maior=-2147483648, total=0, add=1;
	vector<int> count(10001, 0);
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> g[i];
		count[g[i]]++;
		if(g[i]>maior) maior = g[i];
	}
	for(int i=0;i<=maior;i++) {
		if(count[i]!=0) {
			total+=count[i]*add;
			add++;
		}
	}
	cout << total << endl;
	return 0;
}