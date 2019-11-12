// uloha8-3.c -- Ondrej Špánik, 11.11.2019 11:59

#include <stdio.h>

int main()
{
  // sem napis svoje riesenie

	char c1, c2, *p_c;
	
	while((c1 = getchar()) != '*') {
		p_c = &c2;
		*p_c = c1;
		printf("c1: %c (%p), c2: %c (%p), p_c: %c (%p)\n", c1, &c1, c2, &c2, *p_c, p_c);
	}

  return 0;
}
