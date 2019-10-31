#include <stdio.h>

int main() {
	float pi = 3.14;
	float r, o, s;
	scanf("%f", &r);
	printf("Kruh s polomerom %0.2f: obvod = %0.2f, obsah = %0.2f", r, 2*pi*r, pi*r*r);
	return 0;
}
