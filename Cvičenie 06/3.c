#include <stdio.h>

int main() {
    FILE *fr;
    int mn = 0; /* pocet medzier */
    char c;
    if((fr = fopen("text.txt", "r")) == NULL) {
    	printf("Subor text.txt sa nepodarilo otvorit na citanie");
    	return 0;
	}
	while((c = getc(fr)) != EOF) {
		if (c == ' ')
			mn++;
		else if (c == 'x' || c == 'X')
			printf("Precital som X\n");
		else if (c == 'y' || c == 'Y')
			printf("Precital som Y\n");
		else if (c == '#' || c == '$' || c == '&')
			printf("Precital som riadiaci znak\n");
		else if (c == '*') {
			printf("Koniec\n");
			break;
		}
	}
	printf("Pocet precitanych medzier: %d\n", mn);
	
    return 0;
}
