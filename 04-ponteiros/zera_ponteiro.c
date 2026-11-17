#include <stdio.h>

void Zera(int x) {
    x = 0;
}

void ZeraP(int *x) {
    *x = 0;
}

int main() {
    int a = 5, b = 5;

    Zera(a);
    ZeraP(&b);

    printf("%d %d\n", a, b);
    return 0;
}
