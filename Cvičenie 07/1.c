#include <stdio.h>

int main() {
	FILE *fr;
	int pocet_pismen = ('Z' - 'A');
	int pismeno[1000+1][pocet_pismen+1];
	int n = 0;
	int i,j;
	char c;
	
	/* skusi otvorit subor */
	if((fr = fopen("subor.txt", "r")) == NULL) {
		printf("Subor sa nepodarilo otvorit.\n");
		return 0;
	}
	
	/* resetuje pole na nulu */
	for (i=0;i<=1000;i++) {
		for (j=0;j<=pocet_pismen;j++) {
			pismeno[i][j] = 0;
		}	
	}
	
	/* nacita znaky zo suboru a priradi ich do pola len ak su pismena */
	/* nerozlisuje velkost pismen */
	while((c = getc(fr)) != EOF) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			if (c >= 'A' && c <= 'Z')
				c -= 'A';
			else
				c -= 'a';
			pismeno[n][c] += 1;
		}
		else if (c == '\n') {
			n++;
		}
	}
	
	/* vystup */
	for (i=-1;i<=n;i++) { /* riadkovanie */
		if (i == -1) { /* vypis A-Z */
			printf(" ");
			for (j=0;j<=pocet_pismen;j++) {
				printf(" %c",'A'+j);
			}
		}
		else { /* vypis poctov pismen */
			for (j=-1;j<=pocet_pismen;j++) {
				if (j == -1)
					printf("%d",i+1);
				else
					printf(" %d", pismeno[i][j]);
			}
		}
		printf("\n");
	}
	
	fclose(fr);
	
    return 0;
}
