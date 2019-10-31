#include <stdio.h>

int main() {
	int a,b,c;
	char * s;
	scanf("%d %d %d",&a,&b,&c);
	s = ((a+b+c == 180) && (a > 0) && (b > 0) && (c > 0)) ? ("Platny trojuholnik") : ("Neplatny trojuholnik");
	printf("%s\n", s);
	return 0;
}
