#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	if ((n < 1) || (n > 15)) {
		printf("Cislo nie je z daneho intervalu");
		return 0;
	}
	for (i = 1; i <= n; i++) {
		printf("%d:", i);
		for (j = n; j >= i; j--) {
			printf(" %d", j-i+1);
		}
		printf("\n");
	}
	return 0;
}
