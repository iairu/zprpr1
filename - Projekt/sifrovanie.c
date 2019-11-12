#include <stdio.h>

int nacitanie_textu(char *p, int n, int *pn) {
	FILE *fr;
	int i = 0;	  // poradove cislo momentalne nacitaneho znaku
	char c;		  // momentalny znak v subore
	int pocet_znakov = 0;
	if ((fr = fopen("sifra.txt", "r")) == NULL) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}
	while ((c = getc(fr)) != EOF && i <= n) {
		p[i] = c;
		pocet_znakov++;
		i++;
	}
	fclose(fr);
	*pn = pocet_znakov;
	return 0;
}

int vypis_povodny(char *p, int pn) {
	int i;
	if (pn) {
		for(i=0;i<pn;i++)
			putchar(p[i]);
		putchar('\n');
	}
	else {
		printf("Sprava nie je nacitana\n");
		return 0;
	}
	return 0;
}

int uprava_textu(char *p, char *u, int pn, int *un) {
	int i;
	int pocet_znakov = 0;
	if (pn) {
		for(i=0;i<pn;i++) {
			if (p[i] >= 'A' && p[i] <= 'Z') {
				u[pocet_znakov] = p[i];
				pocet_znakov++;
			}
			else if (p[i] >= 'a' && p[i] <= 'z') {
				u[pocet_znakov] = p[i] - 'a' + 'A';
				pocet_znakov++;
			}
		}
	}
	else {
		printf("Sprava nie je nacitana\n");
		return 0;
	}
	*un = pocet_znakov;
	return 0;
}

int vypis_sifrovany(char* u, int un) {
	int i;
	if(un) {
		for(i=0;i<un;i++) {
			putchar(u[i]);
		}
		putchar('\n');
	}
	else {
		printf("Nie je k dispozicii upravena sprava\n");
	}
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

int main() {
	int n = 1000; // max. pocet znakov
	char p[n+1]; // povodny text
	char u[n+1]; // upraveny text
	char c; // uzivatelsky vstup
	int pn = 0; // pocet povodnych znakov
	int un = 0; // pocet upravenych znakov
	while((c = getchar()) != 'k') {
		switch (c) {
			case 'n': nacitanie_textu(p,n,&pn); break;
			case 'v': vypis_povodny(p, pn); 	break;
			case 'u': uprava_textu(p,u,pn,&un); break;
			case 's': vypis_sifrovany(u, un);	break;
			case 'd': vypis_slov_dlzky();		break;
			case 'h': vypis_histogramu(); 		break;
			case 'c': rozsifrovanie();			break;
			case 'k': return 0;				
			default : break;				
		}
	}
    return 0;
}


