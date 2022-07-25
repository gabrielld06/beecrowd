#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, c[7] = {0}, m = 2147483647, t;
    cin >> n;

    while(n--) {
        cin >> d;
        c[d]++;
    }

    for(int i = 1;i < 7;i++) {
        t = 0;
        for(int j = 1;j < 7;j++) {
            if(i != j and i+j == 7) {
                t += c[j]*2;
            } else if(i != j) {
                t += c[j];
            }
        }
        m = (m > t ? t : m);
    }

    cout << m << endl;

    return 0;
}