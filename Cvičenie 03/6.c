#include <stdio.h>
#include <string.h>

int main() {
	int a,b;
	scanf("%d %d", &a, &b);
	
	
	printf((a % 11 == 0) ? ("Prve cislo je delitelne cislom 11\n") : (""));
	printf((b % 5 != 0) ? ("Druhe cislo nie je delitelne cislom 5\n") : (""));
	printf(((a >= 1000) && (b >= 1000)) ? ("Obe cisla su kladne 4-ciferne\n") : (""));
	printf(((a < 0) || (b < 0)) ? ("Aspon jedno z cisel je zaporne\n") : (""));
	printf(((a != 0) && (b != 0)) ? ("Ani jedno z cisel nie je 0\n") : (""));
	
	return 0;
}
