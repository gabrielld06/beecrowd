from math import ceil
v, n = input().split(" ")
v = int(v)
n = int(n)

total = v*n

res = [0,0,0,0,0,0,0,0,0]

for i in range(0, 9):
    res[i] = ceil(total*(i+1)/10)

print(res[0], end = ' ')
print(res[1], end = ' ')
print(res[2], end = ' ')
print(res[3], end = ' ')
print(res[4], end = ' ')
print(res[5], end = ' ')
print(res[6], end = ' ')
print(res[7], end = ' ')
print(res[8])



###################################

#include <stdio.h>
#include <math.h>

int main() {
	int i, v, n, total;
	scanf("%d %d", &v, &n);
	total = v*n;
	for(i=1;i<10;i++) {
		printf("%.0f", ceil((total*i)/10.0));
		if(i!=9) {
			printf(" ");
		}
	}
	printf("\n");
	//printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n", ceil(total*0.1),ceil(total*0.2),ceil(total*0.3),ceil(total*0.4),ceil(total*0.5),ceil(total*0.6),ceil(total*0.7),ceil(total*0.8),ceil(total*0.9));
	return 0;
}