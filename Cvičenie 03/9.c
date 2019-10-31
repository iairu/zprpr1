#include <stdio.h>

int main() {
	float v,h; // v = vyska (cm), h = hmotnost (kg)
	float bmi;
    const char * kat;
	
	scanf("%f %f", &v, &h);
	
	v = v/100; // vyska cm na m
	bmi = h/(v*v); // vzorec bmi
	
    kat =   (bmi <= 18.5) ? ("Podvaha") : (
            ((bmi > 18.5) && (bmi < 25.0)) ? ("Normalna hmotnost") : (
            ((bmi >= 25.0) && (bmi < 30.0)) ? ("Nadvaha") : (
            (bmi >= 30.0) ? ("Obezita") : ("")
            )));

	printf("BMI: %0.3f\n%s", bmi, kat);
	
	return 0;
}
