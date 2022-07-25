#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, s, t1, t2, t3, n, d1, d2, pos[11], skip[11], t;

    while(cin >> p >> s and p and s) {
        memset(pos, 0, sizeof(pos));
        memset(skip, 0, sizeof(skip));
        t = -1;
        cin >> t1 >> t2 >> t3 >> n;
        for(int i = 0;i < n;i++) {
            t = (t + 1) % p;
            cin >> d1 >> d2;

            while(skip[t]) {
                skip[t] = 0;
                t = (t + 1) % p;
                //cout << t << " " << endl;
            }
            pos[t] += d1 + d2;
            //cout << t+1 << ": " << pos[t] << endl;
            if(pos[t] == t1 or pos[t] == t2 or pos[t] == t3) {
                skip[t] = 1;
            }
        }
        cout << t+1 << endl;
    }

    return 0;
}