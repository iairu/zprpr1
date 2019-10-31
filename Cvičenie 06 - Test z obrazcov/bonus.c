#include <stdio.h>

int main() {
	int p,v,o;
	int i,j,k,l,m;
	int n;
	scanf("%d",&p);
	if (p < 1 || p > 100) {
		printf("Nespravny vstup");
		return 0;
	}
	for(i=0;i<p;i++) {
		scanf("%d %d",&v,&o);
		if ((v < 3 || v > 11 || v % 2 == 0) || (o < 1 || o > 7)) {
			printf("Nespravny vstup");
			return 0;
		}
		for(l=0;l<o;l++) { 			/* opakovanie pod sebou <0;o) */
			for(j=0;j<v/2;j++) { 	/* riadkovanie <0;v/2+1) */
				for(n=0;n<=l;n++) {	/* BONUS: opakovanie v riadku (0;l> */
					for(k=0;k<v;k++) { 	/* obsah riadku <0;v) */
						if (k == v/2)
							printf("*");
						else
							printf(".");
					}
				}
				printf("\n");
			}
			for(j=v/2;j>=0;j--) { 	/* riadkovanie <v/2;0> */
				for(n=0;n<=l;n++) {	/* BONUS: opakovanie v riadku (0;l> */
					for(k=0;k<v;k++) { 	/* obsah riadku <0;v) */
						if (k == j || k == v-j-1) /* kde dat hviezdu */
							printf("*");
						else
							printf(".");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
