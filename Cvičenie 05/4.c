#include <stdio.h>

int main() {
	int n, i, k, j;
	scanf("%d", &n);
	if ((n < 1) || (n > 15) || (n % 2 == 0)) {
		printf("Zly vstup");
		return 0;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++)
			printf("*");
		for (k = (n-i); k > 1; k--)
			printf(" ");
		printf("\n");
	}
	for (i = (n - 2); i >= 0; i--) {
		for (j = 0; j <= i; j++)
			printf("*");
		for (k = (n-i); k > 1; k--)
			printf(" ");
		printf("\n");
	}
	return 0;
}
