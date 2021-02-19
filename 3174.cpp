#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int n, x, total=0,arq=0, bon=0, des=0, mus=0;
	string fon, kek;
	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> fon >> kek >> x;
		if(kek=="arquitetos") {
			arq+=x;
		} else if(kek=="bonecos") {
			bon+=x;
		} else if(kek=="desenhistas") {
			des+=x;
		} else {
			mus+=x;
		}
	}
	total = arq/4+bon/8+des/12+mus/6;
	cout << total << endl;
	return 0;
}

