#include <stdio.h>

int main() {
	int n, i;
	float min, max;
	scanf("%d", &n);
	float r[n+1];
	for(i = 0; i < n; i++) {
		scanf("%f", &r[i]);
		
		if (i == 0) {
			max = r[i];
			min = r[i];
		}
		else {
			if (r[i] > max) max = r[i];
			if (r[i] < min) min = r[i];
		}
	}
	printf("Minimum: %0.2f\n", min);
	printf("Maximum: %0.2f\n", max);
	return 0;
	/*
	int n, i;
	float r, min, max;
	min = 100000;
	max = 0;
	scanf("%d", &n);
	for (i = 0;i<n;i++) {
		scanf("%f", &r);
		if (r > max) max = r;
		if (r < min) min = r;
	}
	printf("Minimum: %0.2f\n", min);
	printf("Maximum: %0.2f\n", max);
	return 0;
	*/
}
