#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d, e;
    string s;
    while(cin >> n >> d and n and d) {
        cin >> s;

        stack<int> resp;
        resp.push(-1);
        e = 0;

        for(int i = 0;i < s.length();i++) {
            while(resp.top() != -1 and e < d and s[i] - '0' > resp.top()) {
                resp.pop();
                e++;
            }
            resp.push(s[i] - '0');
        }

        while(e < d) {
            resp.pop();
            e++;
        }

        stack<int> aux;
        aux.push(-1);
        while(resp.top() != -1) {
            aux.push(resp.top());
            resp.pop();
        }
        while(aux.top() != -1) {
            cout << aux.top();
            aux.pop();
        }
        cout << endl;
    }

    return 0;
}