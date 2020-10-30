#include <iostream>

using namespace std;

int min(int x, int y) {
	if(x<y) return x;
	else return y;
}

int menor(int vet[], int left, int right) {
	if(left >= right) return vet[left];
	return min(menor(vet, left, (left+right)/2), menor(vet, (left+right)/2+1, right));
}

int main() {
	int n, i, num;
	
	cin >> n;
	int vet[n];
	for(i=0;i<n;i++) cin >> vet[i];
	num = menor(vet, 0, n-1);
	for(i=0;vet[i]!=num;i++);

	cout << "Menor valor: " << num << "\nPosicao: " << i << endl;
	
	return 0;
}