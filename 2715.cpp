#include <iostream>
#include <vector>

using namespace std;

long long absolute(long long x, long long y) {
	long long dif = x - y;
	if(dif > 0)
		return dif;
	return dif*-1;
}

int main() {
	long long n, aux;
	while(scanf("%lld", &n) != EOF) {
		vector<long long> vet;
		long long sum = 0, sumb = 0;
		while(n--) {
			scanf("%lld", &aux);
			vet.push_back(aux);
			sum += aux;
		}
		long long dif = 9223372036854775807;
		for(int i=0;i<vet.size();i++) {
			//cout << sum << " " << sumb << " " << dif << endl;
			sum -= vet[i];
			sumb += vet[i];
			if(absolute(sum, sumb) <= dif)
				dif = absolute(sum, sumb);
			else break;
		}
		
		cout << dif << endl;
	}
	return 0;
}