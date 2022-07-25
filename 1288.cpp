#include <bits/stdc++.h>

using namespace std;

int memo[51][101];

int p[51], c[51], k;

int pd(int n, int custo) {
    if(memo[n][custo] == -1) {
        if(n == 0 and custo + c[n] > k) memo[n][custo] = 0;
        else if(n == 0) memo[n][custo] = p[0];
        else if(custo + c[n] > k) memo[n][custo] = pd(n-1, custo);
        else memo[n][custo] = max(pd(n-1, custo), p[n] + pd(n-1, custo+c[n]));
    }
    return memo[n][custo];
}

int main() {
    int t, n, r;

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0;i < n;i++) {
            cin >> p[i] >> c[i];
        }
        cin >> k >> r;

        memset(memo, -1, sizeof(memo));

        cout << (pd(n-1, 0) >= r ? "Missao completada com sucesso" : "Falha na missao") << endl;
    }

    return 0;
}