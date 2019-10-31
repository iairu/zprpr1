#include <stdio.h>

int main() {
	int n; /* pocet zahrad*/
	int a,b; /* dlzky stran a,b*/
	int x; /* dlzka pletiva*/
	
	scanf("%d %d %d", &n, &a, &b);
	
	x = (a*n*2)+(b*(n+1)); /* vzorec vypoctu dlzky pletiva */
	
	printf("Na zahrady pouzijeme %d metrov pletiva.", x);
	
	return 0;
}
