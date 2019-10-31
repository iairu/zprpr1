#include <stdio.h>

int main() {
	char c;
	int b1, b2;
	scanf("%c", &c);
	
	// 48 - 57, 65 - 90, 97 - 122
	b1 = ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	b2 = (b1 == 1) ? (0) : (1);
	
	printf("%c je alfanumericky znak: %d\n",c,b1);
	printf("%c nie je alfanumericky znak: %d\n",c,b2);
	return 0;
}
