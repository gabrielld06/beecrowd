#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct tree {
	//char data;
	int num;
	tree* next[26];
};

struct root {
	tree* init[26];
};

void startTree(root* rt) {
	tree aux;
	for(int i = 0;i < 26;i++) {
		rt->init[i] = (tree*)malloc(sizeof(tree));
		//rt->init[i]->data = 97+i;
		rt->init[i]->num = 0;
	}
}

void addNode(tree* rt, int pos) {
	rt->next[pos] =(tree*)malloc(sizeof(tree));
	//rt->next[pos]->data = ch;
	rt->next[pos]->num = 0;
}

void insertWord(tree* rt, string word) {
	rt -> num = rt -> num + 1;
	if(word.length() > 1) {
		int nextPos = tolower(word[1])-97;
		if(rt->next[nextPos] == NULL) {
			addNode(rt, nextPos);
		}
		insertWord(rt->next[nextPos], word.substr(1));
	}
}

int countWord(tree* rt, string word) {
	if(rt != NULL) {
		if(word.length() > 1) {
			int nextPos = tolower(word[1])-97;
			return countWord(rt->next[nextPos], word.substr(1));
		}
		return rt -> num;
	}
	return 0;
}

int main() {
	root rt;
	startTree(&rt);
	string a, b;
	int n, pos, j;
	cin >> n;
	while(n--) {
		cin >> a >> b;
		if(a[0] == 'a') {
			pos = tolower(b[0])-97;
			insertWord(rt.init[pos], b);
		} else if(a[0] == 'f') {
			pos = tolower(b[0])-97;
			cout << countWord(rt.init[pos], b) << endl;
		}
	}
	
	return 0;
}