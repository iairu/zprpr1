#include <stdio.h>

int main() {
	FILE *fw;
	int n, i, j;
	scanf("%d",&n);
	if ((n < 3) || (n > 15) || (n % 2 == 0)) {
		printf("Zly vstup\n");
		return 0;
	}
	if ((fw = fopen("obrazok.txt", "w")) == NULL) {
		printf("Chyba: otvaranie suboru\n");
		return 0;
	}
	n = 2*n-1;
	for(i=0;i<n/2;i++){
		for(j=0;j<=i;j++){
			fprintf(fw, "*");
		}
		for(j=(n-i);j>1;j--){
			fprintf(fw, "-");
		}
		fprintf(fw, "\n");
	}
	for(i=(n/2);i>=0;i--){
		if (i==(n/2)) {
			for(j=0;j<n;j++){
				fprintf(fw, "*");
			}
		}
		else {
			for(j=0;j<=i;j++){
				fprintf(fw, "*");
			}
			for(j=(n-i);j>1;j--){
				fprintf(fw, "o");
			}
		}
		fprintf(fw, "\n");
	}
	if (fclose(fw) == EOF)
		printf("Chyba: zatvaranie suboru\n");
	return 0;
}
