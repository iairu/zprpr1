#include <stdio.h>

int main() {
	int c1,c2,c3,min;
	scanf("%d %d %d",&c1,&c2,&c3);
	min = (c1 < c2) ? ((c1 < c3) ? (c1) : (c3)) : ((c2 < c3) ? (c2) : (c3));
	printf("Najmensie cislo z %d %d %d je: %d\n",c1,c2,c3,min);
	return 0;
}
