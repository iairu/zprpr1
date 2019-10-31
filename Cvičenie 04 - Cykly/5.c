#include <stdio.h>

int main() {
	int f,g,d;
	scanf("%d %d %d", &f, &g, &d);
	while(f <= g) {
		if (!(f % d)) {
			printf("%d", f);
			if (f < g)
				printf(" ");
		}
		f++;
	}
	printf("\n");
	return 0;
}
