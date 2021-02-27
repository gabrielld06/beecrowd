#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<char>> component;
vector<bool> visited;
//Depth first search
void dfs(int v, vector<vector<char>> g, int c) {
	if(!visited[v]) {
		visited[v] = true;
		component[c].push_back(v+97);
		for(vector<char>::iterator i = g[v].begin();i != g[v].end();i++) {
			dfs(*i-97, g, c);
		}
	}
}

int main() {
	int t, caso, n, line;
	vector<char> aux = {};
	cin >> t;
	caso = t;
	while(t--) {
		char aux1, aux2;
		cin >> n >> line;
		vector<vector<char>> g(n, aux);
		vector<bool> aux0(n, false);
		visited = aux0;
		component = {};
		while(line--) {
			cin >> aux1 >> aux2;
			g[aux1-97].push_back(aux2);
			g[aux2-97].push_back(aux1);
		}
		
		int c = 0;
		for(int i = 0; i < n;i++) {
			if(not visited[i]){
				component.push_back({});
				dfs(i, g, c);
				c++;
			}
		}
		
		cout << "Case #" << (caso-t) << ":\n";
		
		for(int i = 0;i < component.size();i++) {
		sort(component[i].begin(), component[i].end());
			for(int j = 0;j < component[i].size();j++) {
				cout << component[i][j] << ",";
			}
			cout << endl;
		}
		cout << c << " connected components\n\n";
	}
	return 0;
}