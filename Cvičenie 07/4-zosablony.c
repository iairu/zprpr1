// uloha7-4.c -- Ondrej Spanik, 4.11.2019 16:59

#include <stdio.h>

int delitele(int x[], int pocetx, int y[], int k)
{
	// sem napis svoje riesenie
	int i;
	int pocety = 0;
	if (k >= 0) {
		for(i=0;i<pocetx;i++){
			if(x[i] > 0 && k % x[i] == 0) {
				y[pocety] = x[i];
				pocety++;
			}
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
	int pocety = delitele(x, pocetx, y, 24);
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
