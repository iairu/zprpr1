#include <stdio.h>
#include <string.h>

// vraj by to malo byt s while loopom

int main() {
	char s[51];
	int i, m, v; /* m = pocet malych pismen, v = pocet velkych */
	m = v = 0;
	scanf("%s", &s);
	for (i = 0; i < strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			v++;
		else if (s[i] >= 'a' && s[i] <= 'z')
			m++;
	}
	printf("%d %d",m,v);
	return 0;
}
