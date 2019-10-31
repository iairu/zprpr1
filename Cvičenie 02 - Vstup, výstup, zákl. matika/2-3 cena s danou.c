#include <stdio.h>

int main() {
	float cena = 0;
	scanf("%f", &cena);
	printf("Cena bez dane: %g\n", cena);
	printf("Predajna cena s danou 20\%: %0.1f", cena*1.2);
	return 0;
}
