#include <stdio.h>

int main() {
    int n, NumeroTriangular;

    for (n = 0; n < 100; n++) {
        NumeroTriangular = (n * (n + 1)) / 2;
        printf("%d\n", NumeroTriangular);
    }

    return 0;
}

