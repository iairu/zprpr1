#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Only thing missing is a proper way to pause the program 
// when a character sequence gets inputed.
// getchar() obviously doesn't work in this case.

int main() {
	process();
	printf("\n----------------------------\nPress any key to exit...");
	getchar();
	return 0;
}

int process() {
	FILE *fr, *fw;
	char path[50] = "";
	char c, lc, y;
	int i, j, k, a;
	a = y = 0;
	
	printf("Path to lyrics: ");
	fgets(path, 256, stdin);
	if (strlen(path) > 0) {
		if (path[strlen(path) - 1] == '\n')
        	path[strlen(path) - 1] = '\0';
		if (path[0] == '"') {
			for (i = 0; i <= strlen(path); i++)
				path[i] = path[i+1];
		}
		if (path[strlen(path) - 1] == '"')
        	path[strlen(path) - 1] = '\0';
	}
	if ((fr = fopen(path, "r")) == NULL) {
		printf("Couldn't open file \"%s\"", path);
		return 0;
	}
		
	printf("Amplitude: ");
	scanf("%d", &a);
	if (!(a > 0)) {
		printf("Amplitude %d has to be above 0", a);
		return 0;
	}
	
	printf("Yell (Y) or be quiet (Q)?: ");
	scanf("%c", &y);
	if (!(((y == 'y') || (y == 'Y')) || (y == 'q') || (y == 'Q'))) {
		printf("Specified value %c is not y, Y, q, Q", y);
		return 0;
	}
	
	printf("----------------------------\n");
	
	lc = '\n';
	j = k = 0;
	while((c = getc(fr)) != EOF) {
		if (y == 'y' || y == 'Y') {
			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
		}
		else {
			if (c >= 'A' && c <= 'Z')
				c += 'a' - 'A';
		}
		if (lc == '\n') {
			for (i = j; i <= a; i++) {
				printf("#");
			}
			for (i = j; i <= a; i++) {
				printf("-");
			}
			printf("> ");
			if ((k == 0) && (j < a))
				j++;
			else if ((k == 1) && (j > 0))
				j--;
			else {
				k = (k == 1) ? (0) : (1);
			}
		}
		putchar(c);
		lc = c;
	}
	
	fclose(fr);
	return 0;
}
