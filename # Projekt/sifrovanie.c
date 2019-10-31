#include <stdio.h>


int main() {
	char p[1001]; // povodny text
	char u[1001]; // upraveny text
	prikaz(p, u);
	//printf("Obsah pola povodneho textu: %s",p);
	//printf("Obsah pola upraveneho txtu: %s",u);
    return 0;
}

int prikaz(char *p, char *u) {
	switch (getchar()) {
		case 'n': nacitanie_textu(p); 	break;
		case 'v': vypis_povodny(); 		break;
		case 'u': uprava_textu(); 		break;
		case 's': vypis_sifrovany(); 	break;
		case 'd': vypis_slov_dlzky(); 	break;
		case 'h': vypis_histogramu(); 	break;
		case 'c': rozsifrovanie(); 		break;
		case 'k': return 0;				
		default : break;				
	}
	prikaz(p, u);
}

int nacitanie_textu(char *p) {
	FILE *fr;
	int n = 1000; // max. pocet znakov na nacitanie
	int i = 0;	  // poradove cislo momentalne nacitaneho znaku
	char c;		  // momentalny znak v subore
	if ((fr = fopen("sifra.txt", "r")) == NULL) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}
	while ((c = getc(fr)) != EOF && i <= n) {
		p[i] = c;
		i++;
	}
	fclose(fr);
	return 0;
}

int vypis_povodny() {
	printf("vypis_povodny pojde sem\n");
	return 0;
}

int uprava_textu() {
	printf("uprava_textu pojde sem\n");
	return 0;
}

int vypis_sifrovany() {
	printf("vypis_sifrovany pojde sem\n");
	return 0;
}

int vypis_slov_dlzky() {
	printf("vypis_slov_dlzky pojde sem\n");
	return 0;
}

int vypis_histogramu() {
	printf("vypis_histogramu pojde sem\n");
	return 0;
}

int rozsifrovanie() {
	printf("rozsifrovanie pojde sem\n");
	return 0;
}
