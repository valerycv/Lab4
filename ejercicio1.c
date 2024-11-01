#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Llenar la matriz con valores aleatorios binarios
void fillMatrix(int *matrix, int size) {
    for (int i = 0; i < size * size; i++) {
        *(matrix + i) = rand() % 2;
    }
}

// Imprimir la matriz
void printMatrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", *(matrix + i * size + j));
        }
        printf("\n");
    }
}

// Encontrar la secuencia de 1s más larga en filas
int findLongestSequence(int *matrix, int size) {
    int longest_sequence = 0, current_sequence = 0;

    for (int i = 0; i < size * size; i++) {
        if (*(matrix + i) == 1) {
            current_sequence++;
            if (current_sequence > longest_sequence) {
                longest_sequence = current_sequence;
            }
        } else {
            current_sequence = 0;
        }
    }
    return longest_sequence;
}

// Calcular la transpuesta de la matriz
void transposeMatrix(int *matrix, int *transpose, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(transpose + j * size + i) = *(matrix + i * size + j);
        }
    }
}

int main() {
    int size;
    printf("Ingrese el tamaño de la matriz cuadrada: ");
    scanf("%d", &size);

    // Reserva de memoria dinámica para la matriz y la transpuesta
    int *matrix = (int *)malloc(size * size * sizeof(int));
    int *transpose = (int *)malloc(size * size * sizeof(int));

    if (!matrix || !transpose) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Llenado y despliegue de la matriz original
    srand(time(0));
    fillMatrix(matrix, size);
    printf("Matriz original:\n");
    printMatrix(matrix, size);

    // Encontrar secuencia más larga en la matriz original
    int longest_sequence = findLongestSequence(matrix, size);
    printf("La secuencia más larga de 1s en la matriz original es: %d\n", longest_sequence);

    // Calcular y desplegar la matriz transpuesta
    transposeMatrix(matrix, transpose, size);
    printf("Matriz transpuesta:\n");
    printMatrix(transpose, size);

    // Encontrar secuencia más larga en la transpuesta
    int longest_sequence_transpose = findLongestSequence(transpose, size);
    printf("La secuencia más larga de 1s en la matriz transpuesta es: %d\n", longest_sequence_transpose);

    // Liberar memoria
    free(matrix);
    free(transpose);

    return 0;
}