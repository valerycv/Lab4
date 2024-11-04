#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para la secuencia más larga de 1s consecutivos
int findLongestSequence(int *matrix, int n) {
    int longest = 0, current = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(matrix + i * n + j) == 1) {
                current++;
            } else {
                if (current > longest) longest = current;
                current = 0;
            }
        }
        // Al final de cada fila, actualiza si hay una secuencia más larga
        if (current > longest) longest = current;
    }

    return longest;
}

// Función para llenar la matriz de manera aleatoria
void fillMatrixRandomly(int *matrix, int n) {
    srand(time(0));
    for (int i = 0; i < n * n; i++) {
        *(matrix + i) = rand() % 2;
    }
}

// Función que imprime la matriz
void printMatrix(int *matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(matrix + i * n + j));
        }
        printf("\n");
    }
}

// Función que calcula la transpuesta de la matriz
int* transposeMatrix(int *matrix, int n) {
    int *transposed = (int *)malloc(n * n * sizeof(int));
    if (transposed == NULL) {
        fprintf(stderr, "Error al asignar memoria para la matriz transpuesta.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(transposed + j * n + i) = *(matrix + i * n + j);
        }
    }

    return transposed;
}

int main() {
    int n;
    printf("Ingrese el tamaño de la matriz nxn: ");
    scanf("%d", &n);

    // Valida el tamaño de la matriz
    if (n < 1) {
        printf("Tamaño no válido. Se usará el tamaño por defecto de 5.\n");
        n = 5;
    }

    // Asignación memoria dinámica para la matriz
    int *matrix = (int *)malloc(n * n * sizeof(int));
    if (matrix == NULL) {
        fprintf(stderr, "Error al asignar memoria para la matriz.\n");
        return 1;
    }

    // Llenado aleatorio de la matriz
    fillMatrixRandomly(matrix, n);
    printf("Matriz generada:\n");
    printMatrix(matrix, n);

    // Encontrar la secuencia más larga de 1s en la matriz original
    int longestSequence = findLongestSequence(matrix, n);
    printf("La secuencia más larga de 1s en la matriz es: %d\n", longestSequence);

    // Calcular y buscar en la transpuesta
    int *transposedMatrix = transposeMatrix(matrix, n);
    printf("Matriz transpuesta:\n");
    printMatrix(transposedMatrix, n);

    int longestSequenceTransposed = findLongestSequence(transposedMatrix, n);
    printf("La secuencia más larga de 1s en la matriz transpuesta es: %d\n", longestSequenceTransposed);

    // Liberar memoria
    free(matrix);
    free(transposedMatrix);

    return 0;
}
