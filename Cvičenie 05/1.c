#include <stdio.h>

int main() {
	int n, i, a, j;
	scanf("%d", &n);
	if ((n >= 1) && (n <= 10)) {
		a = i = 0;
		while (i < n) {
			for (j = 0; j <= i; j++) {
				a++;
				printf("%d", a);
				if (j != i)
					printf(" ");
			}
			printf("\n");
			i++;
		}
	}
	else {
		printf("Nespravny vstup");
	}
	return 0;
}
