#include <stdio.h>

int main() {
	int n, i, k, j, m, s, c;
	scanf("%d %d", &n, &s);
	if ((n < 1) || (n > 15) || (n % 2 == 0) || (s < 1) || (s > 5)) {
		printf("Zly vstup");
		return 0;
	}
	m = 0;
		for (i = 0; i < ((n-1)/2); i++) {
			for (c = 0; c < s; c++) {
				for (j = 0; j < n; j++) {
					if ((j == (n-1)/2) || (j == m) || (j == (n-m-1)))
						printf("*");
					else {
						printf("-");
					}
				}
			}
			printf("\n");
			m++;
		}
		for (i = 0; i < n*s; i++) {
			printf("*");
		}
		printf("\n");
		m = (n-1)/2+1;
		for (i = ((n-1)/2); i > 0; i--) {
			for (c = 0; c < s; c++) {
				for (j = 0; j < n; j++) {
					if ((j == (n-1)/2) || (j == m) || (j == (n-m-1)))
						printf("*");
					else {
						printf("-");
					}
				}
			}
			printf("\n");
			m++;
		}
	return 0;
}
