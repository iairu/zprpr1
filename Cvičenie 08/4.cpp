#include <stdio.h>

void uprav_zlomok(int* citatel, int* menovatel) {
	int i;
	for (i = 2; i <= *menovatel; i++)
		while (*citatel % i == 0 && *menovatel % i == 0) {
			*citatel /= i;
			*menovatel /= i;
		}
}

int main() {
	int x,y;
	scanf("%d %d", &x, &y);
	uprav_zlomok(&x,&y);
	printf("Zakladny tvar zlomku: %d/%d\n", x, y);
    return 0;
}
