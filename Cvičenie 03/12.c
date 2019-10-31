#include <stdio.h>

int main() {
    int a,b,c,d,e,max;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    max = a;
    max = (b > max) ? (b) : (max);
    max = (c > max) ? (c) : (max);
    max = (d > max) ? (d) : (max);
    max = (e > max) ? (e) : (max);
    printf("%d",(a+b+c+d+e-max));
    return 0;
	/*
    int a[6];
    int sum = 0;
    int i,j,n;
    scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);

    for (i = 0; i < 5; i++) {
        n = 0;
        for (j = 0; j < 5; j++) {
            if ((a[i] >= a[j]))
                n++;
        }
        if (n == 5)
            continue;
        else
            sum += a[i];
    }
    printf("%d",sum);
    */
}