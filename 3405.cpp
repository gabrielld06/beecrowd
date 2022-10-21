#include <iostream>
 
using namespace std;
 
int main() {
 
    int x, i = 5, ans = 0;
    cin >> x;
    
    while(x / i != 0) {
        ans += x / i;
        i *= 5;
    }
    
    cout << ans << endl;

 
    return 0;
}