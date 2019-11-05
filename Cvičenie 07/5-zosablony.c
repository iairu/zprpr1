// uloha7-5.c -- Ondrej Špánik, 4.11.2019 17:08


#include <stdio.h>

double skalarny_sucin(double *a, double *b, int n)
{
  // sem napis svoje riesenie
	double sucin = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		sucin += a[i]*b[i];
	}
	return sucin;
}

int main()
{
  int i, n;
  double a[100], b[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%lf", &a[i]);
  for (i = 0; i < n; i++)
    scanf("%lf", &b[i]);
  printf("%.2lf\n", skalarny_sucin(a, b, n));
  return 0;
}
