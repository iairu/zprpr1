// uloha9-5.c -- Ondrej Špánik, 18.11.2019 12:08

#include <stdio.h>
#include <string.h>

void odstran_male_pismena(char *str)
{
  // sem napis svoje riesenie
  char *p, *q;
  for(p=str,q=str;*p != '\0';p++) {
    if(*p >= 'A' && *p <= 'Z') {
      *q=*p;
      q++;
    }
  }
  *q='\0';
}

int main()
{
  char buf[1000];
  while(scanf("%s", buf) == 1)
  {
    odstran_male_pismena(buf);
    printf("%s\n", buf);
  }
  return 0;
}