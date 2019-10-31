#include <stdio.h>

int main() {
	int i = 0;
	int n = 1;
	FILE *fr_prvy, *fr_druhy, *fw;
	char c_prvy, c_druhy;
	if((fr_prvy = fopen("prvy.txt", "r")) == NULL) {
	    printf("Subor prvy.txt sa nepodarilo otvorit r");
	    return 0;
	}
	if((fr_druhy = fopen("druhy.txt", "r")) == NULL) {
	    printf("Subor druhy.txt sa nepodarilo otvorit r");
	    return 0;
	}
	if((fw = fopen("treti.txt", "w")) == NULL) {
        printf("Subor treti.txt sa nepodarilo otvorit w");
        return 0;
    }
    while (i < n) {
    	if (i % 2 == 0 && c_prvy != EOF) {
    		if (n > 1)
				putc(' ',fw);
			putc('+',fw);
		    while((c_prvy = getc(fr_prvy)) != EOF) {
		    	if (c_prvy == ' ' || c_prvy == '\n') {
		    		if ((c_prvy = getc(fr_prvy)) == EOF)
		    			break;
		    		else {
		    			ungetc(c_prvy, fr_prvy);
					}
		    		break;
				}
		    	else {
		    		putc(c_prvy,fw);
		    		n++;
				}
			}
		}
		else if (c_druhy != EOF) {
    		if (n > 1)
				putc(' ',fw);
			putc('-',fw);
			while((c_druhy = getc(fr_druhy)) != EOF) {
		    	if (c_druhy == ' ' || c_druhy == '\n') {
		    		if ((c_druhy = getc(fr_druhy)) == EOF)
		    			break;
		    		else {
		    			ungetc(c_druhy, fr_druhy);
					}
		    		break;
				}
		    	else {
		    		putc(c_druhy,fw);
		    		n++;
				}
			}
		}
		i++;
	}
	putc('\n',fw);
    return 0;
}
