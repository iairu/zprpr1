#include <stdio.h>

int main() {
	int n,i;
	float sum, out, avg;
	sum = avg = out = 0.0;
	scanf("%d", &n);
	float r[n+1];
	for(i = 0; i < n; i++) {
		scanf("%f", &r[i]);
		if (i > 0) {
			if (r[i] > avg)
				out += r[i];
		}
		else {
			out += r[i];
		}
		sum += r[i];
		avg = sum/(i+1);
	}
	printf("%0.2f\n", out);
	return 0;
}
