// uloha9-4.c -- Ondrej Špánik, 18.11.2019 11:56

#include <stdio.h>
#include <string.h>

void vloz_do_stredu(char *str, char c)
{
  char *p;
  char dlzka = strlen(str);
  char stred = dlzka/2;
  for(p=str+dlzka;p>=str+stred;p--) {
    *(p+1)=*p;
  }
  *(p+1)=c;
  // sem napis svoje riesenie
}

int main()
{
  char buf[1000], znak[10];
  while(scanf("%s %s", buf, znak) == 2)
  {
    vloz_do_stredu(buf, znak[0]);
    printf("%s\n", buf);
  }
  return 0;
}