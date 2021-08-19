#include <bits/stdc++.h>
// problema dos intervalos ponderados
// weighted interval scheduling
using namespace std;

int memo[1001], p[1001];

void merge(int s[], int f[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux, *vetsAux;
    vetAux = (int*)malloc(tam * sizeof(int));
    vetsAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(f[com1] < f[com2]) {
            vetAux[comAux] = f[com1];
            vetsAux[comAux] = s[com1];
            com1++;
        } else {
            vetAux[comAux] = f[com2];
            vetsAux[comAux] = s[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){
        vetAux[comAux] = f[com1];
        vetsAux[comAux] = s[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {
        vetAux[comAux] = f[com2];
        vetsAux[comAux] = s[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){
        f[comAux] = vetAux[comAux-comeco];
        s[comAux] = vetsAux[comAux-comeco];
    }
    
    free(vetAux);
    free(vetsAux);
}

void mergeSort(int s[], int f[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(s, f, comeco, meio);
        mergeSort(s, f, meio+1, fim);
        merge(s, f, comeco, meio, fim);
    }
}

void calculo_p(int s[], int f[], int n) {
	int i, j;
	for(i=n-1;i>=0;i--) {
		j=i-1;
		while(s[i] < f[j] && j>=0) j--;
		p[i] = j;
	}
}

int opt(int s[], int f[], int n) {
	if(n < 0) return 0;
	
	if(memo[n] == -1) {
		memo[n] = max(f[n] - s[n] + opt(s, f, p[n]), opt(s, f, n-1));
	}
	
	return memo[n];	
}

int main() {
	int n, s[1001], f[1001];
	
	cin >> n;
	
	for(int i = 0;i < n; ++i) {
		cin >> s[i] >> f[i];
	}
	
	mergeSort(s, f, 0, n-1);
	calculo_p(s, f, n);
	memset(memo, -1, sizeof(int) * n);
	
	cout << opt(s, f, n-1) << "\n";
	
	return 0;
}