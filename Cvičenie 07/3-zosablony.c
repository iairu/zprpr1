// uloha7-3.c -- Ondrej Špánik, 4.11.2019 12:53

#include <stdio.h>

int nasobky(int x[], int pocetx, int y[], int k)
{
	// sem napis svoje riesenie
	int i;
	int pocety = 0;
	if (k >= 0) {
		for(i=0;i<pocetx;i++){
			if(x[i] % k == 0) {
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
	int pocety = nasobky(x, pocetx, y, 2);
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
