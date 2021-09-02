#include <bits/stdc++.h>
 
using namespace std;

bool rail(int entrada[], int n) {
	int saida = n, i = n-1;
	stack<int> pilha;
	pilha.push(-1);
	pilha.push(entrada[i]);
	i--;
	while(i >= 0) {
		while(pilha.top() == saida) {
			pilha.pop();
			saida--;
		}
		pilha.push(entrada[i]);
		i--;
	}
	while(pilha.top() == saida) {
		pilha.pop();
		saida--;
	}
	return saida == 0 ? true : false;
}

int main() {
	int n, saida[10001];
	while(cin >> n and n) {
		while(true) {
			cin >> saida[0];
			if(not saida[0]) {
				cout << endl;
				break;
			}
			for(int i = 1;i < n;i++) {
				cin >> saida[i];
			}
			
			cout << (rail(saida, n) ? "Yes" : "No") << endl;
		}
	}	
	
    return 0;
}