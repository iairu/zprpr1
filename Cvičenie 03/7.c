#include <stdio.h>

int main() {
	float f;
	float c;
	scanf("%f", &f);
	c = (f-32)*5/9;
	printf("%0.2f\n", c);
	printf((c<0) ? ("Mrzne") : ((c >= 100) ? ("Vrie") : ("")));
	return 0;
}
