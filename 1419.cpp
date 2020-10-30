#include <iostream>

using namespace std;

int main() {
	int r = 1, i, m[10], l[10], extra = 0, total_m = 0, total_l = 0;
	int last_m[3] = {-1 , -1, -1}, last_l[3] = {-1, -1, -1}, m_igual = 0,  l_igual = 0;
	while (r!=0) {
		total_m = 0;
		total_l = 0;
		extra = 0;
		cin >> r;
		for(i=0;i<r;i++)
			cin >> m[i];
		for(i=0;i<r;i++)
			cin >> l[i];
		for(i=0;i<r;i++) {
			m_igual = 0;
			l_igual = 0;
			total_m += m[i];
			last_m[0] = last_m[1];
			last_m[1] = last_m[2];
			last_m[2] = m[i];
			total_l += l[i];
			last_l[0] = last_l[1];
			last_l[1] = last_l[2];
			last_l[2] = l[i];
			if (last_m[0] == last_m[1] && last_m[1] == last_m[2])
				m_igual=1;
			if (last_l[0] == last_l[1] && last_l[1] == last_l[2])
				l_igual=1;
			if(i > 1 && !extra) {
				if(m_igual && l_igual) {
					extra = 1;
				} else if (m_igual) {
					total_m += 30;
					extra = 1;
				} else if (l_igual) {
					total_l += 30;
					extra = 1;
				}
			}
		}
		if(total_m > total_l  && r != 0)
			cout << "M\n";
		else if(total_l > total_m  && r != 0)
			cout << "L\n";
		else if (total_l == total_m && r != 0)
			cout << "T\n";
	}
	return 0;
}