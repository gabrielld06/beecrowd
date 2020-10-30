#include <iostream>

using namespace std;

long long int memo[51][100001];

long long int ginastica(long long int t, long long int min, long long int max, long long int dif) {
	if(memo[t][dif] == -1) {
		if(dif == min) {
			memo[t][dif] = ginastica(t-1, min, max, dif+1);
		} else if(dif == max){
			memo[t][dif] = ginastica(t-1, min, max, dif-1);
		} else {
			memo[t][dif] = ginastica(t-1, min, max, dif-1) + ginastica(t-1, min, max, dif+1);
		}
	}
	return memo[t][dif];
}

long long int g(long long int t, long long int min, long long int max, long long int dif) {
	int i, j;
	for(i=1;i<t+1;i++){
		for(j=min;j<max+1;j++) {
			if(memo[i][j] == -1) {
				if(j == min) {
					memo[i][j] = memo[i-1][j+1];
				} else if(j == max){
					memo[i][j] = memo[i-1][j-1];
				} else {
					memo[i][j] = memo[i-1][j-1] + memo[i-1][j+1];
				}
			}
		}
	}
	return memo[t][dif];
}

int main() {
	long long int tot = 0, i, j, t, min, max;
	
	cin >> t >> min >> max;

	for(i=min;i<max+1;i++) 
			memo[1][i] = 1;

	for(i=2;i<t+1;i++) 
		for(j=min;j<max+1;j++)
			memo[i][j] = -1;
	
	for(i=min;i<=max;i++) {
		tot += g(t, min, max, i);
		tot = tot%1000000007;
	}
	
	cout << tot << endl;
	
	return 0;
}

long long int ginastica(long long int t, long long int min, long long int max, long long int dif) {
	if(t == 1) {
		return 1;
	}else if(dif == min) {
		return = ginastica(t-1, min, max, dif+1);
	} else if(dif == max){
		return = ginastica(t-1, min, max, dif-1);
	} else {
		return = ginastica(t-1, min, max, dif-1) + ginastica(t-1, min, max, dif+1);
	}
}