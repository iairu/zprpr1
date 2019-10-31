#include <stdio.h>

int main() {
	int n, i, nc;
	nc = 0;
	scanf("%d", &n);
	int a[n+1];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if ((a[i] > 0) && (a[i] <= 100))
			nc++;
	}
	printf("%d\n", nc);
	return 0;
}
