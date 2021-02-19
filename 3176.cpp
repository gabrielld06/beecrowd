#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct anao {
	int idade;
	int indice;
};

void merge(anao vetor[], int comeco, int meio, int fim, vector<string> nomes) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    anao *vetAux;
    vetAux = (anao*)malloc(tam * sizeof(anao));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1].idade < vetor[com2].idade) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else if(vetor[com1].idade == vetor[com2].idade){
			if(nomes[vetor[com1].indice] > nomes[vetor[com2].indice]) {
				vetAux[comAux] = vetor[com1];
				com1++;
			} else {
				vetAux[comAux] = vetor[com2];
				com2++;
			}
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(anao vetor[], int comeco, int fim, vector<string> nomes){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio, nomes);
        mergeSort(vetor, meio+1, fim, nomes);
        merge(vetor, comeco, meio, fim, nomes);
    }
}

int main() {
	int n, kek, num, times[11][31];
	string fon;
	vector<string> nomes;
	anao maozinha[31];
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> fon >> kek;
		nomes.push_back(fon);
		maozinha[i].idade = kek;
		maozinha[i].indice = i;
	}
	mergeSort(maozinha, 0, n-1, nomes);
	num = n/3;
	int pos = n-1;
	for(int i=0;i<num;i++) {
		cout << "Time " << i+1 << endl;
		cout << nomes[maozinha[pos].indice] << " " << maozinha[pos].idade << endl;
		cout << nomes[maozinha[pos-num].indice] << " " << maozinha[pos-num].idade << endl;
		cout << nomes[maozinha[pos-2*num].indice] << " " << maozinha[pos-2*num].idade << endl;
		cout << endl;
		pos--;
	}
	return 0;
}