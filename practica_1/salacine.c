//Programa sala de cine
//autor: Santiago
// modificador: Jimmmy
// versión 1.1.1
// Corrección de la falla en la introducción de datos, ya que si se ponía menos  o mas de los solicitados el programa se cerraba no se ejecutaba o fallaba

#include <stdio.h>

int main() {
    int multiarreglo[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    int sala = 0; 
    int fila, columna;

    while (sala < 20) {
        printf("\n--- ESTADO DE LA SALA ---\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                printf(" %2d ", multiarreglo[i][j]);
            }
            printf("\n");
        }

        printf("\nEscoge el asiento\n");
        printf("Escribe la fila (0-4) y columna (0-3)\n");

        printf("Fila: ");
       
        if (scanf("%d", &fila) != 1) {
            printf("Error: Por favor, ingresa solo números enteros.\n");
            while(getchar() != '\n'); 
            continue;
        }

        printf("Columna: ");
        if (scanf("%d", &columna) != 1) {
            printf("Error: Por favor, ingresa solo números enteros.\n");
            while(getchar() != '\n');
            continue;
        }

  
        if (fila >= 0 && fila < 5 && columna >= 0 && columna < 4) {
           
            if (multiarreglo[fila][columna] == 0) {
                printf("¡Ese asiento ya está ocupado! Por favor elige otro.\n");
            } else {
                multiarreglo[fila][columna] = 0;
                sala++;
                printf("¡Asiento reservado con éxito!\n");
            }
        } else {
            printf("Error: Fila o columna fuera de los límites.\n");
        }
    }

    printf("\n¡La sala está completamente llena!\n");
    return 0;
}
