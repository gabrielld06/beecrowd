#include <iostream>

using namespace std;

struct coord {
	int x;
	int y;
};

int max(int x, int y) {
	if(x>y) return x;
	return y;
}

void merge(coord vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    coord *vetAux;
    vetAux = (coord*)malloc(tam * sizeof(coord));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1].x < vetor[com2].x) {
            vetAux[comAux] = vetor[com1];
            com1++;
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

void mergeSort(coord vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int onda(coord pontos[], int pos, int a, int con, coord sol[], int j) {
	int addMais, addMenos, add, nadd;
	if(pos==-1) {
		return 0;
	} else if(con==0) {
		sol[j].x = pontos[pos].x;
		sol[j].y = pontos[pos].y;
		addMais = 1 + onda(pontos, pos-1, pontos[pos].y+1, 1, sol, j+1);
		addMenos = 1 + onda(pontos, pos-1, pontos[pos].y-1, 1, sol, j+1);
		nadd = onda(pontos, pos-1, a, 0, sol, j);
		return max(max(addMais, addMenos), nadd);
	}
	if(pontos[pos].x != sol[j-1].x && abs(pontos[pos].y - sol[j-1].y) == 2 && (pontos[pos].y == a+1 || pontos[pos].y == a-1)) {
		sol[j].x = pontos[pos].x;
		sol[j].y = pontos[pos].y;
		add = 1 + onda(pontos, pos-1, a, 1, sol, j+1);
		nadd = onda(pontos, pos-1, a, 1, sol, j);
		return max(add, nadd);
	}
	return onda(pontos, pos-1, a, 1, sol, j);
}


int main() {
	int n;
	coord pontos[1001], sol[1001];
	while(cin >> n) {
		for(int i=0;i<n;i++) {
			cin >> pontos[i].x >> pontos[i].y;
		}
		mergeSort(pontos, 0, n-1);
		cout << onda(pontos, n-1, 0, 0, sol, 0) << endl;
	}
}