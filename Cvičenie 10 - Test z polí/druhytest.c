// test2.c -- Ondrej Špánik, 25.11.2019 11:06


#include <stdio.h>
#include <string.h>


#define LEN_AK_UPRAVENE if(u[0] == '\0'){printf("Nie je k dispozicii upravena sprava\n"); return 0;}
#define LEN_AK_NACITANE if(p[0] == '\0'){printf("Sprava nie je nacitana\n"); return 0;}


int nacitanie_textu(char *p, int n) {
        FILE *fr;
        int i = 0;          // poradove cislo momentalne nacitaneho znaku
        char c;                  // momentalne nacitany znak
        
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
        
        int k;        // hladana dlzka
        int l;        // najdena dlzka
        
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
        int n = 26;                        // pocet pismen abecedy
        int dlzka = 0;                // dlzka upraveneho pola
        int pocet[n+1];                // pocet vyskytu pismena
        int pocet_h[n+1];        // pocet hviezdiciek na pismeno
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
        for(riadok=0;riadok<max_pocet_h;riadok++) {                /* riadkovanie */
                for(i=0;i<n;i++) {                                                        /* ide od A po Z */
                        if(pocet_h[i]>=max_pocet_h-riadok) {        /* hviezdickuje len ak... */
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
        int n;        // o kolko sa ma pismeno posunut v abecede
        char c;        // pomocna premenna na momentalne pismeno
        
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


int medzi_indexami(char *p) {
        LEN_AK_NACITANE


        int i;
        int z,k;


        scanf("%d %d", &z, &k);


        /*         vypis povodnej spravy medzi z a k (vratane)
                + nahradenie nepismeniek pluskami */
        for(i=z;i<=k;i++){
                if((p[i] < 'A' || p[i] > 'Z') && (p[i] < 'a' && p[i] > 'z')) {
                        putchar(p[i]);
                }
                else {
                        putchar('+');
                }
        }
        putchar('\n');


        return 0;
}


int vlozenie_do_stredu(char *u) {
        LEN_AK_UPRAVENE


        int i = 0;
        char c;
        char r[12];
        int stred_u = strlen(u)/2;


        getchar(); /* zoberie jednu medzeru */
        /* vstup od používateľa do reťazca r kým nenarazí na nový riadok */
        while((c = getchar()) != '\n' && i < 10) {
                r[i] = c;
                i++;
        }
        r[i] = '\0';


        /* podmienky */
        /* r ma najviac 10 znakov */
        /* neziskame spravu nad 1000 znakov */
        /* u musi mat parny pocet znakov */
        if ((strlen(r) > 10) ||
                (strlen(u)+strlen(r) > 1000) ||
                (strlen(u) % 2 !=0)) {
                printf("Retazec nie je mozne vlozit\n");
                return 0;
        }
        /* r musi obsahovat len velke pismena */
        for(i=0;i<strlen(r);i++) {
                if(r[i] < 'A' || r[i] > 'Z') {
                        printf("Retazec nie je mozne vlozit\n");
                        return 0;
                }
        }


        /* uvolnenie miesta pre retazec r */
        for(i=strlen(u);i>=stred_u;i--){
                u[i+strlen(r)] = u[i];
        }
        /* vlozenie retazca r do u */
        for(i=0;i<strlen(r);i++) {
                u[stred_u+i] = r[i];
        }


        printf("Retazec sa vlozil\n");
        return 0;
}


int bonus(char *u) {
        LEN_AK_UPRAVENE


        int k, i;
        char c, d;
        int pocet_c;
        int max_c = 0;
        int max_c_k = 0;
        
        scanf("%c",&c);
        
        for(k=0;k<=25;k++) {


                /* cezarova sifra + pocitanie poctu c pre k */
                pocet_c = 0;
                for(i=0;u[i]!='\0';i++) {
                        if(u[i] >= 'A' && u[i] <= 'Z') {
                                d = u[i]-k;
                                if(d<'A')
                                        d = d - 'A' + 'Z' + 1;
                                if(d == c)
                                        pocet_c++;
                        }
                }
                
                /* priradenie k s max poctom c ak sa naslo */
                if (pocet_c > max_c)
                        max_c_k = k;
        }


        printf("%d\n",max_c_k);
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
                        case 'n': nacitanie_textu(p,n);         break;
                        case 'v': vypis_povodny(p);                 break;
                        case 'u': uprava_textu(p,u);                break;
                        case 's': vypis_sifrovany(u);                break;
                        case 'd': vypis_slov_dlzky(p);                break;
                        case 'h': vypis_histogramu(u);                break;
                        case 'c': rozsifrovanie(u);                        break;
                        case 'p': medzi_indexami(p);                 break;
                        case 'z': vlozenie_do_stredu(u);         break;
                        case 'b': bonus(u);                                        break;
                        case 'k': return 0;                                
                        default : break;                                
                }
        }
    return 0;
}