#Autor:Jimmy
#Modificador:Jose Santiago Alegria Ponce
#Fecha 26/marzo/2026
#Versión 1.2.0
#Se agrego un sistema completo de dulceria despues de hacer la compra de boleto
#consiste en un nuevo arreglo como el de los asientos 
#integra sistema de compra y cambio 


#include <stdio.h>
#include <stdbool.h>

// Definimos una estructura para los combos
struct Combo {
    char nombre[50];
    float precio;
};

void comprar_combo() {
    printf("\n--- DULCERÍA ---\n");
    
    // Arreglo de combos disponibles
    struct Combo combos[3] = {
        {"Combo Individual (Palomitas + Refresco)", 150.0},
        {"Combo Pareja (2 Refrescos + Palomitas G)", 280.0},
        {"Combo Familiar (4 Refrescos + 2 Palomitas G)", 450.0}
    };

    for (int i = 0; i < 3; i++) {
        printf("%d. %s - $%.2f\n", i + 1, combos[i].nombre, combos[i].precio);
    }
    printf("0. Saltar dulcería\n");

    int opcion;
    printf("\nSelecciona el número de combo: ");
    scanf("%d", &opcion);

    if (opcion == 0) {
        printf("No se agregó combo.\n\n");
        return;
    }

    if (opcion >= 1 && opcion <= 3) {
        float precio = combos[opcion - 1].precio;
        float pago;

        printf("Has elegido: %s\n", combos[opcion - 1].nombre);
        printf("Total a pagar: $%.2f\n", precio);
        printf("Ingresa la cantidad con la que pagas: $");
        scanf("%f", &pago);

        if (pago >= precio) {
            printf("Pago exitoso. Tu cambio es: $%.2f\n", pago - precio);
            printf("¡Disfruta tu película y tus palomitas!\n\n");
        } else {
            printf("Dinero insuficiente. Faltan $%.2f. Compra cancelada.\n\n", precio - pago);
        }
    } else {
        printf("Opción no válida.\n\n");
    }
}

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
        printf("--- ESTADO DE LA SALA ---\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 4; j++) {
                if (multiarreglo[i][j] == 0) {
                    printf("  X "); // Asiento ocupado
                } else {
                    printf("%3d ", multiarreglo[i][j]);
                }
            }
            printf("\n");
        }

        printf("\nEscoge el asiento\n");
        printf("Escribe la fila (0-4) y columna (0-3): ");
        
        // Validación básica de entrada numérica
        if (scanf("%d %d", &fila, &columna) != 2) {
            printf("Error: Ingresa solo números enteros.\n");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
            continue;
        }

        if (fila >= 0 && fila < 5 && columna >= 0 && columna < 4) {
            if (multiarreglo[fila][columna] == 0) {
                printf("¡Ese asiento ya está ocupado! Intenta de nuevo.\n\n");
            } else {
                multiarreglo[fila][columna] = 0;
                sala++;
                printf("¡Asiento reservado con éxito!\n");
                
                // Llamamos a la función de la dulcería
                comprar_combo();
            }
        } else {
            printf("Error: Fila o columna fuera de límites.\n\n");
        }
    }

    printf("¡La sala está completamente llena!\n");
    return 0;
}
