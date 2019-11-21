// uloha9-6.c -- Ondrej Špánik, 18.11.2019 12:19
#include <stdio.h>
#include <stdlib.h>

// Funkcia vygeneruje postupku do retazca str: zacinajucu znakom z, dlzky len.
void postupka(char *str, char z, int len)
{
  // sem napis svoje riesenie
  char *p=str;
  if((len>0) && (z >= 'a' || z <= 'z') && (z >= 'A' || z <= 'Z')) {
    while(p<str+len){
      *p=z;
      if(z=='z' || z=='Z')
        z=z-'z'+'a';
      else
        z++;
      p++;
    }
  }
  *p = '\0';
    
}

// ukazkovy test (spracovanie vstupu)
int main(void)
{
  char z[2], *buf;
  int n;

  // nacitanie vstupu
  while (scanf("%s %d", z, &n) == 2)
  {
    buf = malloc(n + 1); // vyhradim n+1 znakov pre retazec
    postupka(buf, z[0], n);
    printf("%s\n", buf);
    free(buf); // uvolnim vyhradene miesto
  }
  return 0;
}