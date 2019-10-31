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
		for (j = 1; j <= ((n - i) + 1); j++)
			printf(" %d", j);
		printf("\n");
	}
	return 0;
}
