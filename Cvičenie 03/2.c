#include <stdio.h>

int main() {
	char c1, c2;
	scanf("%c %c", &c1, &c2);
	if ((c1 > 90 || c1 < 65) || (c2 > 90 || c2 < 65)) {
		printf("Neboli zadane velke pismena.");
		return 0;
	}
	printf("%c %c\n", c2-65+97, c1-65+97);
	return 0;
}
