// uloha9-3.c -- Ondrej Špánik, 18.11.2019 11:35

#include <stdio.h>

int nasobky(int x[], int y[], int pocet, int k)
{
  // sem napis svoje riesenie
  int *p, *q;
  for(p=x, q=y;p<x+pocet;p++) {
    if(*p != 0 && *p % k == 0) {
      *q=*p;
      q++;
    }
  }
  return q-y;
}

int main()
{
  // sem napis svoje riesenie
  int x[50], y[50];
  int *p;
  int n, k;
  int pocet_nasobkov;
  scanf("%d %d",&n,&k);
  for(p=x;p<x+n;p++) {
    scanf(" %d", p);
  }
  pocet_nasobkov = nasobky(x,y,n,k);
  printf("Pocet nasobkov cisla %d: %d\n",k,pocet_nasobkov);
  printf("Nasobky:");
  for(p=y;p<y+pocet_nasobkov;p++){
    printf(" %d",*p);
  }
  return 0;
}