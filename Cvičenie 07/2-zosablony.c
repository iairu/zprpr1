// uloha7-2.c -- Ondrej Špánik, 4.11.2019 12:11

#include <stdio.h>

int parne(int x[], int pocetx, int y[])
{
  // sem napis svoje riesenie
  int i;
  int pocety = 0;
  for(i=0;i<pocetx;i++) {
    if (x[i] % 2 == 0) {
      y[pocety] = x[i];
      pocety++;
    }
  }
  return pocety;
}

int main()
{
  int i, x[10], pocetx;
  scanf("%d", &pocetx);
  for (i = 0; i < pocetx; i++)
    scanf("%d", &x[i]);

  int y[10];
  int pocety = parne(x, pocetx, y);
  printf("pocety: %d\ny: {", pocety);
  for (i = 0; i < pocety; i++)
  {
    if (i > 0)
      printf(", ");
    printf("%d", y[i]);
  }
  printf("}\n");
  return 0;
}
