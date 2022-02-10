#include <bits/stdc++.h>

using namespace std;

int n, m, k;

class Vertex {
	public:
	int degree = 0;
	bool visited = false;
	vector<int> e;
};

void dfs_visit(Vertex v[1001], int at) {
	if(v[at].degree < k) {
		for(int i = 0;i < v[at].e.size();i++) {
			if(v[at].e[i] != -1) {
				int vt = v[at].e[i];
				v[at].e[i] = -1;
				if(v[vt].degree >= k) {
					v[vt].degree--;
					dfs_visit(v, vt);
				}
			}
		}
	}
}

void dfs(Vertex v[1001]) {
	for(int i = 1;i <= n;i++) {
		if(not v[i].visited)
			dfs_visit(v, i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	int v1, v2, j;
	bool notFind;
	
	while(cin >> n) {
		cin >> m >> k;
		Vertex v[1001];
		for(int i = 0;i < m;i++) {
			cin >> v1 >> v2;
			v[v1].e.push_back(v2);
			v[v2].e.push_back(v1);
			v[v1].degree++;
			v[v2].degree++;
		}
		if(k*(k-1)/2 > m) cout << 0 << "\n";
		else {
			dfs(v);
			notFind = true;
			j = 1;
			while(notFind and j <= n) {
				if(v[j].degree >= k) {
					cout << j;
					notFind = false;
				}
				j++;
			}
			for(;j <= n;j++) {
				if(v[j].degree >= k) {
					cout << " " << j;
				}
			}
			//cout << notFind << endl;
			if(notFind) {
				cout << "0";
			}
			cout << endl;
		}
	}
	
	return 0;
}