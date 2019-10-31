#include <stdio.h>

int main() {
	int a,b;
	int b1,b2,b3,b4,b5;
	scanf("%d %d", &a, &b);
	
	b1 = (a % 11 == 0) ? (1) : (0);
	printf("Prve cislo je delitelne cislom 11: %d\n", b1);
	
	b2 = (b % 5 != 0) ? (1) : (0);
	printf("Druhe cislo nie je delitelne cislom 5: %d\n", b2);
	
	b3 = ((a >= 1000) && (b >= 1000)) ? (1) : (0);
	printf("Obe cisla su kladne 4-ciferne: %d\n", b3);
	
	b4 = ((a < 0) || (b < 0)) ? (1) : (0);
	printf("Aspon jedno z cisel je zaporne: %d\n", b4);
	
	b5 = ((a != 0) && (b != 0)) ? (1) : (0);
	printf("Ani jedno z cisel nie je 0: %d\n", b5);
	
	return 0;
}
