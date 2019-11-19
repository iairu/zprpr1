#include <stdio.h>

int nacitanie_textu(char *p, int n) {
	FILE *fr;
	int i = 0;	  // poradove cislo momentalne nacitaneho znaku
	char c;		  // momentalny znak v subore
	if ((fr = fopen("sifra.txt", "r")) == NULL) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}
	if ((c = getc(fr)) == EOF) {
		printf("Spravu sa nepodarilo nacitat\n");
		return 0;
	}
	else {
		ungetc(c,fr);
	}
	while ((c = getc(fr)) != EOF && i <= n) {
		p[i] = c;
		i++;
	}
	p[i] = '\0';
	fclose(fr);
	return 0;
}

int vypis_povodny(char *p) {
	int i;
	if (p[0] != '\0') {
		for(i=0;p[i]!='\0';i++)
			putchar(p[i]);
		putchar('\n');
	}
	else {
		printf("Sprava nie je nacitana\n");
		return 0;
	}
	return 0;
}

int uprava_textu(char *p, char *u) {
	int i;
	int pocet_znakov = 0;
	if (p[0] != '\0') {
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
	}
	else {
		printf("Sprava nie je nacitana\n");
		return 0;
	}
	u[pocet_znakov] = '\0';
	return 0;
}

int vypis_sifrovany(char* u) {
	int i;
	if(u[0] != '\0') {
		for(i=0;u[i]!='\0';i++) {
			putchar(u[i]);
		}
		putchar('\n');
	}
	else {
		printf("Nie je k dispozicii upravena sprava\n");
	}
	return 0;
}

int vypis_slov_dlzky(char* p) {
	int k;
	int x;
	char *q = p;
	char *r;
	if (*q == '\0') {
		printf("Sprava nie je nacitana\n");
		return 0;
	}
	scanf("%d", &k);
	if (k >= 1 && k <= 100) {
		x = 1;
		while(1) {
			if(*q == ' ' || *q == '\0' || *q == '\n') {
				if(x == k+1){
					/* ked sa najde slovo danej dlzky */
					for(r=q-k;r<q;r++)
						putchar(*r);
					putchar('\n');
				}
				x = 0;
			}
			if(*q == '\0')
				break;
			x++;
			q++;
		}
	}
	return 0;
}

int vypis_histogramu(char* u) {
	int i;
	int n = 26;
	char c[n+1];
	char *q = u;
	char *r = c;
	if (*q == '\0') {
		printf("Nie je k dispozicii upravena sprava\n");
		return 0;
	}
	/* vynulovanie pola c */
	for(i=0;i<n;i++)
		c[i]=0;
	c[i+1] = '\0';
	/* pripocitavanie do pola c pre vsetky pismena abecedy */
	while(*q != '\0') {
		i = -1;
		
		/* aby sa male aj velke pismena pripocitavali do rovnakeho indexu
		if(*q >= 'a' && *q <= 'z') {
			i = (int)(*q-'a');
		}
		else if...*/
		if(*q >= 'A' && *q <= 'Z') {
			i = (int)(*q-'A');
		}
		
		if (i >= 0)
			c[i]++;
		q++;
	}
	printf("Pocet a: %d\n",c[0]);
	printf("Pocet b: %d\n",c[1]);
	printf("Pocet t: %d\n",c[19]);
	printf("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	return 0;
}

int rozsifrovanie() {
	printf("rozsifrovanie pojde sem\n");
	return 0;
}

int main() {
	int n = 1000; // max. pocet znakov
	char p[n]; // povodny text
	char u[n]; // upraveny text
	char c; // uzivatelsky vstup
	p[0] = '\0';
	u[0] = '\0';
	while((c = getchar()) != 'k') {
		switch (c) {
			case 'n': nacitanie_textu(p,n); 	break;
			case 'v': vypis_povodny(p); 		break;
			case 'u': uprava_textu(p,u);		break;
			case 's': vypis_sifrovany(u);		break;
			case 'd': vypis_slov_dlzky(p);		break;
			case 'h': vypis_histogramu(u);		break;
			case 'c': rozsifrovanie();			break;
			case 'k': return 0;				
			default : break;				
		}
	}
    return 0;
}


