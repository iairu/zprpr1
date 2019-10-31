#include <stdio.h>

int main() {
	int p; // p = pocet ludi
	int i,j,k; // iteratory
    int a,b,c,d; // countery na vahove kategorie
    a = b = c = d = 0;
	
	scanf("%d", &p);
	
	float v[p+1]; // v = vyska (cm)
	float h[p+1]; // h = hmotnost (kg)
	float bmi[p+1];
	
	for (i = 0; i < p; i++) {
		scanf("%f %f", &v[i], &h[i]);
		v[i] = v[i]/100; // vyska cm na m
	}
	
	for (j = 0; j < p; j++) {
		bmi[j] = h[j]/(v[j]*v[j]); // vzorec bmi
		printf("%0.2f\n", bmi[j]);
		
		// pridelenie do counterov
		(bmi[j] <= 18.5) ? (a++) : (
	    ((bmi[j] > 18.5) && (bmi[j] < 25.0)) ? (b++) : (
	    ((bmi[j] >= 25.0) && (bmi[j] < 30.0)) ? (c++) : (
	    (bmi[j] >= 30.0) ? (d++) : (0)
	    )));
	}
    
    printf("Podvaha: %d\n", a);
    printf("Normalna hmotnost: %d\n", b);
    printf("Nadvaha: %d\n", c);
    printf("Obezita: %d\n", d);
	
	return 0;
}
