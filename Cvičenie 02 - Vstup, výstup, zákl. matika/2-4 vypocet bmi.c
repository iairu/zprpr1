#include <stdio.h>

int main() {
	float v,h; // v = vyska (cm), h = hmotnost (kg)
	float bmi;
	
	scanf("%f %f", &v, &h);
	
	v = v/100; // vyska cm na m
	bmi = h/(v*v); // vzorec bmi
	
	printf("BMI: %0.3f", bmi);
	
	return 0;
}
