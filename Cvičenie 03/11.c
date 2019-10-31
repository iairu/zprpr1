#include <stdio.h>

int main() {
	char a,b,c;
    scanf("%c %c %c",&a,&b,&c);
    if ((a == b) && (a == c))
        printf("Vsetky pismena su rovnake\n");
    else if ((a == b) || (a == c) || (b == c))
        printf("Dve pismena su rovnake\n");
    else
        printf("Vsetky pismena su rozne\n");
    return 0;
}