#include <stdio.h>

int main() {
	int f,g;
	scanf("%d %d", &f, &g);
	while(f <= g) {
		if (!(f % 3)) {
			printf("%d", f);
			if (f < g)
				printf(" ");
		}
		f++;
	}
	printf("\n");
	return 0;
}
