#include <stdio.h>

int main() {
	FILE *fr;
	int pocet_pismen = ('Z' - 'A');
	int pismeno[pocet_pismen+1];
	int n = 0;
	int j;
	int c;
	char nazov_suboru[50] = "";
	scanf("%s",nazov_suboru);
	
	/* skusi otvorit subor */
	if((fr = fopen(nazov_suboru, "r")) == NULL) {
		printf("Subor sa nepodarilo otvorit.\n");
		return 0;
	}
	
	/* resetuje pole na nulu */
	for (j=0;j<=pocet_pismen;j++) {
		pismeno[j] = 0;
	}
	
	/* vystup riadku A-Z */
	printf(" ");
	for (j=0;j<=pocet_pismen;j++) {
		printf(" %c",'A'+j);
	}
	printf("\n");
	
	/* nacita znaky zo suboru a priradi ich do pola len ak su pismena */
	/* nerozlisuje velkost pismen */
	/* na novom riadku vypise pocty pismen v riadku */
	while((c = getc(fr)) != EOF) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			if (c >= 'A' && c <= 'Z')
				c -= 'A';
			else
				c -= 'a';
			pismeno[c] += 1;
		}
		else if (c == '\n') {
			/* vystup*/
			printf("%d",n+1);
			for (j=0;j<=pocet_pismen;j++)
					printf(" %d", pismeno[j]);
			printf("\n");
			
			/* resetuje pole na nulu */
			for (j=0;j<=pocet_pismen;j++) {
				pismeno[j] = 0;
			}
			n++;
		}
	}
	
	fclose(fr);
	
    return 0;
}
