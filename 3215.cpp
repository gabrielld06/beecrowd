#include <bits/stdc++.h>

using namespace std;

vector<int> nodeValue;
vector<bool> visited;
vector<vector<int>> nodeNeighbors;

int dfsVisit(int i) {
	int sum = nodeValue[i];
	visited[i] = true;
	for(auto k : nodeNeighbors[i]) {
		if(not visited[k]) {
			sum += dfsVisit(k);
		}
	}
	return sum;
}

bool dfs(int n) {
	for(int i = 0;i < n;i++) {
		if(not visited[i] and dfsVisit(i)) {
			return false;
		}
	}
	return true;
}

int main() {
	int x, y, n, m;
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> x;
		nodeValue.push_back(x);
		visited.push_back(false);
		nodeNeighbors.push_back(vector<int>());
	}
	
	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		nodeNeighbors[x].push_back(y);
		nodeNeighbors[y].push_back(x);
	}
	
	cout << (dfs(n) ? "POSSIBLE" : "IMPOSSIBLE") << "\n";

    return 0;
}