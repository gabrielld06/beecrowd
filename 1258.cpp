#include <bits/stdc++.h>

using namespace std;

class camiseta {
	public:
	string name, cor;
	char tam;
	
	camiseta(string n, string c, char t) {
		this->name = n;
		this->cor = c;
		this->tam = t;
	}
	
	bool operator <(const camiseta& x) {
		if(cor != x.cor)
			return cor < x.cor;

		if(tam != x.tam)
			return tam > x.tam;
		
		return name < x.name;
	}
};

int main() {
	int n;
	string name, color;
	char tam;
	bool first = true;
	while(cin >> n and n) {
		if(not first) {
			cout << endl;
		}
		first = false;
		vector<camiseta> c;
		for(int i = 0;i < n;i++) {
			getline(cin, name);
			getline(cin, name);
			cin >> color >> tam;
			
			c.push_back(camiseta(name, color, tam));
		}

		sort(c.begin(), c.end());
		
		for(auto ca : c) {
			cout << ca.cor << " " << ca.tam << " " << ca.name << endl;
		}

	}
	return 0;
}