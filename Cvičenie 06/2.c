#include <stdio.h>

int main() {
    FILE *fr, *fw;
    char c;
    int mn = 0; /* pocet malych pismen */
    
    if((fr = fopen("VSTUP.TXT", "r")) == NULL) {
    	printf("Subor VSTUP.TXT sa nepodarilo otvorit na citanie");
    	return 0;
	}
    if((fw = fopen("cisla.txt", "a")) == NULL) {
    	printf("Subor cisla.txt sa nepodarilo otvorit na zapis (append)");
    	return 0;
	}
	while((c = getc(fr)) != EOF) {
		if(c != '\n') {
			putc(c, fw);
			if(c >= 'a' && c <= 'z')
				mn++;
		}
		else {
			fprintf(fw, "\n%d\n", mn);
			mn = 0;
		}
	}
    return 0;
}
