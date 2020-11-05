#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>

using namespace std;

struct casa {
	int x;
	int y;
};

int main() {
	int n, x, y, cidade=1;
	double totalc, totalp;
	string med;
	casa cs[1000001];
	int vet[201];
	cin >> n;
	while(n != 0) {
		totalc = 0, totalp = 0;
		for(int i=0;i<201;i++) vet[i] = 0;
		for(int i=0;i<n;i++) {
			cin >> cs[i].x >> cs[i].y;
			vet[cs[i].y/cs[i].x]+=cs[i].x;
			totalp += cs[i].x;
			totalc += cs[i].y;
		}
		cout << "Cidade# " << cidade++ << ":" << endl;
		for(int i=0;i<201;i++) {
			if(vet[i]!=0) {
				cout << vet[i] << "-" << i << " ";
			}
		}
		med = to_string(totalc/totalp);
		cout << "\nConsumo medio: " << med.substr(0, med.find(".")+3) << " m3." << endl;
		cin >> n;
		if(n!=0) cout << endl;
	}
	return 0;
}