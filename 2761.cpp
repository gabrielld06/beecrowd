#include <bits/stdc++.h>

using namespace std;

int main() {
	int integer;
	float real;
	char ch;
	char str[50];
		
	cin >> integer >> real >> ch;
	cin.ignore();
	scanf("%[^\n]s", str);
	
	printf("%d%.6f%c%s\n", integer, real, ch, str);
	printf("%d\t%.6f\t%c\t%s\n", integer, real, ch, str);
	printf("%10d%10.6f%10c%10s\n", integer, real, ch, str);

	return 0;
}