#include <stdio.h>

int main() {
	int n, i, k, j, m, l, v;
	scanf("%d %d", &n, &v);
	if ((n < 1) || (n > 15) || (n % 2 == 0) || (v < 1) || (v > 5)) {
		printf("Zly vstup");
		return 0;
	}
	for (l = 0; l < v; l++) {
	m = 0;
		for (i = 0; i < ((n-1)/2); i++) {
			for (j = 0; j < n; j++) {
				if (j == (n-1)/2)
					printf("*");
				else {
					if ((j == m) || (j == (n-m-1)))
						printf("*");
					else
						printf("-");
				}
			}
			printf("\n");
			m++;
		}
		for (i = 0; i < n; i++) {
			printf("*");
		}
		printf("\n");
		m = (n-1)/2+1;
		for (i = (n-1)/2; i > 0; i--) {
			for (j = 0; j < n; j++) {
				if (j == (n-1)/2)
					printf("*");
				else {
					if ((j == m) || (j == (n-m-1)))
						printf("*");
					else
						printf("-");
				}
			}
			printf("\n");
			m++;
		}
	}
	return 0;
}
