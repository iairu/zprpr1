#include <stdio.h>

int main() {
    char c,d;
    FILE *fr, *fw;
    scanf("%c",&c);
    if((fr = fopen("znak.txt", "r")) == NULL) {
    	printf("Subor znak.txt sa nepodarilo otvorit na citanie");
    	return 0;
	}
	if (c == 's') {
		/* do suboru novy.txt */
	    if((fw = fopen("novy.txt", "w")) == NULL) {
	    	printf("Subor novy.txt sa nepodarilo otvorit na zapis");
	    	return 0;
		}
		while ((d = fgetc(fr)) != EOF) {
			putc(d,fw);
		}
	}
	else {
		/* stdout */
		while ((d = fgetc(fr)) != EOF) {
			putchar(d);
		}
	}
    return 0;
}
