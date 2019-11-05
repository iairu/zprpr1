#include <stdio.h>

int main() {
	int n;
	int i;
	int x[51];
	int y[51];
	scanf("%d",&n);
	if (n > 50)
		return 0;
	for (i=0;i<n;i++)
		scanf("%d",&x[i]);
	printf("Povodne pole: ");
	for (i=0;i<n;i++)
		printf(" %d",x[i]);
	printf("\nPocet parnych prvkov pola:");
	parne = parne(x,y,51);
	
    return 0;
}

int parne(int x[], int y[], int pocet) {
	int i;
	int parne = 0;
	for (i=0;i<pocet;i++){
		if (x[pocet] % 2 == 0)
			parne += 1;
	}
	
			y[pocet] = x[pocet];
	
	return 0;
}
