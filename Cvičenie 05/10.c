#include <stdio.h>

int main() {
	FILE *fr;
	int n = 0;
	int pocet = 0;
//	int max = 0;
	int min = 0;
	char c;
	if ((fr = fopen("list.txt", "r")) == NULL) {
		printf("Chyba: otvaranie suboru\n");
		return 0;
	}
	while (c = getc(fr)) {
		if ((c == '\n') || c == EOF) {
			n++;
//			if (pocet > max)
//				max = pocet;
			if ((pocet < min) || (n == 1))
				min = pocet;
			pocet = 0;
		}
		else {
			pocet++;
		}
		if (c == EOF)
			break;
	}
//	printf("Min: %d\nMax: %d\n", min,max);
 	printf("%d", min);
	if (fclose(fr) == EOF)
		printf("Chyba: zatvaranie suboru\n");
	return 0;
}
