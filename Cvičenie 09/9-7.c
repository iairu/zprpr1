// uloha9-7.c -- Ondrej Špánik, 18.11.2019 12:42

#include <stdio.h>
#include <string.h>

int main() {
	char riadok[256];
	char vyskyt[256];
	char *p, *q;
	int h; /* bool ci je vriadku hviezdicka */
	
	while(scanf("%s",riadok) == 1) {
		h = 0;
		for(p=riadok,q=vyskyt;p<riadok+strlen(riadok);p++,q++){
			if(*p == '*') {
				*q = '^';
				h = 1;	
			}
			else {
				*q = ' ';
			}
		}
		*p = '\0';
		*q = '\0';
		if (h) {
			printf("%s\n",riadok);
			printf("%s\n",vyskyt);
		}
	}
	
	return 0;
}