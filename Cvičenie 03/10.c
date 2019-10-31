#include <stdio.h>

int main() {
    int m,d;
    scanf("%d", &m);
    if (!((m >= 1) && (m <= 12))) {
        printf("Neplatne cislo mesiaca");
        return 0;
    }
    d = (m == 2) ? (28) : ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) ? (31) : (30));
    printf("Mesiac cislo %d ma %d dni\n", m, d);
    return 0;
}
