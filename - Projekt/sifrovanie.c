#include <stdio.h>

#define LEN_AK_UPRAVENE if(u[0] == '\0'){printf("Nie je k dispozicii upravena sprava\n"); return 0;}
#define LEN_AK_NACITANE if(p[0] == '\0'){printf("Sprava nie je nacitana\n"); return 0;}

int nacitanie_textu(char *p, int n) {
	FILE *fr;
	int i = 0;	  // poradove cislo momentalne nacitaneho znaku
	char c;		  // momentalne nacitany znak
	
	// otvorenie a osetrenie suborov
	if ((fr = fopen("sifra.txt", "r")) == NULL) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}
	if ((c = getc(fr)) == EOF) { // dodatocna kontrola podla mailu: prazdne subory su tiez chybne
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}
	else
		ungetc(c,fr);
	
	// nacitavanie	
	while ((c = getc(fr)) != EOF && i <= n) {
		p[i] = c;
		i++;
	}
	p[i] = '\0';
	
	fclose(fr);
	return 0;
}

int vypis_povodny(char *p) {
	LEN_AK_NACITANE
	
	int i;
	for(i=0;p[i]!='\0';i++)
		putchar(p[i]);
	putchar('\n');
	return 0;
}

int uprava_textu(char *p, char *u) {
	LEN_AK_NACITANE
	
	int i;
	int pocet_znakov = 0;
	
	// prehodi len pismena do upraveneho textu, male da na velke
	for(i=0;p[i]!='\0';i++) {
		if (p[i] >= 'A' && p[i] <= 'Z') {
			u[pocet_znakov] = p[i];
			pocet_znakov++;
		}
		else if (p[i] >= 'a' && p[i] <= 'z') {
			u[pocet_znakov] = p[i] - 'a' + 'A';
			pocet_znakov++;
		}
	}
	u[pocet_znakov] = '\0';
	
	return 0;
}

int vypis_sifrovany(char* u) {
	LEN_AK_UPRAVENE
	
	int i;
	for(i=0;u[i]!='\0';i++) {
		putchar(u[i]);
	}
	putchar('\n');
	return 0;
}

int vypis_slov_dlzky(char* p) {
	LEN_AK_NACITANE
	
	int k;	// hladana dlzka
	int l;	// najdena dlzka
	
	char *q = p;
	char *r;
	
	scanf("%d", &k);
	if (!(k >= 1 && k <= 100))
		return 0;
		
	l = 0;
	while(1) {
		l++;
		if(*q == ' ' || *q == '\0' || *q == '\n') {
			if(l == k+1){
				/* ked sa najde slovo danej dlzky */
				for(r=q-k;r<q;r++)
					putchar(*r);
				putchar('\n');
			}
			l = 0;
		}
		if(*q == '\0')
			break;
		q++;
	}
	
	return 0;
}

int vypis_histogramu(char* u) {
	LEN_AK_UPRAVENE
	
	int i, riadok;
	int n = 26;			// pocet pismen abecedy
	int dlzka = 0;		// dlzka upraveneho pola
	int pocet[n+1];		// pocet vyskytu pismena
	int pocet_h[n+1];	// pocet hviezdiciek na pismeno
	int max_pocet_h = 0;// treba na zistenie vysky histogramu
	
	char *q = u;
	
	/* vynulovanie pola pocet pismen */
	for(i=0;i<n;i++)
		pocet[i]=0;
	pocet[i+1] = '\0';
	
	/* pripocitavanie do pola pocet pre vsetky velke pismena abecedy */
	while(*q != '\0') {
		i = (int)(*q-'A');
		pocet[i]++;
		dlzka++;
		q++;
	}
	
	/* pocet_h[i]: kolko hviezdiciek na pismeno + max_pocet_h na vysku histogramu */
	for(i=0;i<n;i++){
		if(pocet[i]>0)
			pocet_h[i] = (100/dlzka*pocet[i]-1)/10+1;
		else
			pocet_h[i] = 0;
		if(pocet_h[i] > max_pocet_h)
			max_pocet_h = pocet_h[i];
	}
	
	/* vypis histogramu */
	for(riadok=0;riadok<max_pocet_h;riadok++) {		/* riadkovanie */
		for(i=0;i<n;i++) {							/* ide od A po Z */
			if(pocet_h[i]>=max_pocet_h-riadok) {	/* hviezdickuje len ak... */
				putchar('*');
				pocet_h[i]--;
			}
			else
				putchar(' ');
		}
		putchar('\n');
	}
	printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	
	return 0;
}

int rozsifrovanie(char* u) {
	LEN_AK_UPRAVENE
	
	int i;
	int n;	// o kolko sa ma pismeno posunut v abecede
	char c;	// pomocna premenna na momentalne pismeno
	
	scanf("%d", &n);
	if(n<1 || n > 25)
		return 0;
		
	/* keby rekurzivne kontrolujeme abecedu ak povolime n>26
	if(n>26)
		n %= 26;
	*/
	for(i=0;u[i]!='\0';i++) {
		if(u[i] >= 'A' && u[i] <= 'Z') {
			c = u[i];
			c -= n;
			/* keby sa pismena posuvali dopredu (nie dozadu)
			if(c>'Z')
				c = c - 'Z' + 'A' - 1;
			else*/ 
			if(c<'A')
				c = c - 'A' + 'Z' + 1;
			putchar(c);
		}
	}
	putchar('\n');
	return 0;
}

int main() {
	int n = 1000; // max. pocet znakov
	char p[n+1]; // povodny text
	char u[n+1]; // upraveny text
	char c; // uzivatelsky vstup
	p[0] = '\0'; // na zistenie ci bolo do pola nacitane
	u[0] = '\0'; // ^
	while((c = getchar()) != 'k') {
		switch (c) {
			case 'n': nacitanie_textu(p,n); 	break;
			case 'v': vypis_povodny(p); 		break;
			case 'u': uprava_textu(p,u);		break;
			case 's': vypis_sifrovany(u);		break;
			case 'd': vypis_slov_dlzky(p);		break;
			case 'h': vypis_histogramu(u);		break;
			case 'c': rozsifrovanie(u);			break;
			case 'k': return 0;				
			default : break;				
		}
	}
    return 0;
}

