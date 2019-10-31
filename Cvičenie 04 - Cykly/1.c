#include <stdio.h>

int main() {
	float t;
	const char * out;
	scanf("%f", &t);
	out = 	(t <= 0) ? ("Mrzne") : (
			((t > 0) && (t < 100)) ? ("Normalna teplota") : (
			(t >= 100) ? ("Vrie") : ("")));
	printf("%s\n", out);
	return 0;
}
