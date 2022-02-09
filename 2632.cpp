#include <bits/stdc++.h>

using namespace std;

class Enemy {
	public:
	double x, y, w, h;
};

class Magic {
	public:
	double x, y, r, d;
};

bool colision(Enemy e, Magic m){

    double Xn = max(e.x, min(m.x, e.x+e.w));
    double Yn = max(e.y, min(m.y, e.y+e.h));
     
    double Dx = Xn - m.x;
    double Dy = Yn - m.y;
    return (Dx * Dx + Dy * Dy) <= m.r * m.r;
}

int main() {
	int n, nv;
	Enemy e;
	Magic m;
	string name;
	
	cin >> n;
	
	double radiusF[3] = {20, 30, 50};
	double radiusW[3] = {10, 25, 40};
	double radiusE[3] = {25, 55, 70};
	double radiusA[3] = {18, 38, 60};
	
	for(int t = 0;t < n;t++) {
		cin >> e.w >> e.h >> e.x >> e.y;
		cin >> name >> nv >> m.x >> m.y;
		
		if(name == "fire") {
			m.r = radiusF[nv-1];
			m.d = 200.0;
		} else if(name == "water") {
			m.r = radiusW[nv-1];
			m.d = 300.0;
		} else if(name == "earth") {
			m.r = radiusE[nv-1];
			m.d = 400.0;
		} else {
			m.r = radiusA[nv-1];
			m.d = 100.0;
		}
		
		if(colision(e, m)) cout << m.d << endl;
		else cout << 0 << endl;
	}
	
	return 0;
}