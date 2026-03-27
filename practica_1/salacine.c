//#Autor:Jose Santiago Alegria Ponce
//#Modificador: Hernandez Garcia Juan Carlos 
//#Fecha 26/marzo/2026
//#Versión 1.2.1
//En la dulcería usé %-42s para que los precios queden perfectamente alineados en una columna, sin importar el largo del nombre del combo.
//Sistema de Abonos: En lugar de cancelar la compra si falta dinero, el sistema ahora te permite seguir "metiendo monedas" hasta completar el pago.
//Pre-visualización: El mapa ahora muestra claramente qué número es la fila y cuál es la columna, reduciendo errores del usuario.

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// --- ESTRUCTURAS ---
struct Combo {
    char nombre[50];
    float precio;
};

// --- PROTOTIPOS ---
void limpiar_buffer();
void imprimir_sala(int sala[5][4]);
void comprar_combo();

// --- FUNCIONES ---

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimir_sala(int sala[5][4]) {
    printf("\n      --- MAPA DE LA SALA ---\n");
    printf("      Col:  0   1   2   3\n"); // Guía de columnas
    printf("     --------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Fila %d |", i); // Guía de filas
        for (int j = 0; j < 4; j++) {
            if (sala[i][j] == 0) {
                printf("  X "); 
            } else {
                printf("%3d ", sala[i][j]);
            }
        }
        printf("\n");
    }
    printf("     --------------------\n");
}

void comprar_combo() {
    struct Combo combos[3] = {
        {"Combo Individual (Palomitas + Refresco)", 150.0},
        {"Combo Pareja (2 Refrescos + Palomitas G)", 280.0},
        {"Combo Familiar (4 Refrescos + 2 Palomitas G)", 450.0}
    };

    printf("\n--- DULCERÍA (v1.2.1) ---\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %-42s $%.2f\n", i + 1, combos[i].nombre, combos[i].precio);
    }
    printf("0. Saltar dulcería\n");

    int opcion;
    printf("\nSelecciona tu combo: ");
    if (scanf("%d", &opcion) != 1) {
        limpiar_buffer();
        printf("Opción inválida. Volviendo a la sala...\n");
        return;
    }

    if (opcion == 0) return;

    if (opcion >= 1 && opcion <= 3) {
        float precio = combos[opcion - 1].precio;
        float pago = 0;

        printf("Total: $%.2f\n", precio);
        
        // Lógica de pago mejorada (v1.2.1)
        while (pago < precio) {
            float abono;
            printf("Ingrese pago (Faltan $%.2f): $", precio - pago);
            if (scanf("%f", &abono) != 1) {
                limpiar_buffer();
                printf("Error en moneda. Reintente.\n");
                continue;
            }
            pago += abono;
            
            if (pago < precio) {
                printf("Aún no es suficiente.\n");
            }
        }

        printf("¡Pago exitoso! Su cambio: $%.2f\n", pago - precio);
        printf("Disfrute sus productos.\n\n");
    } else {
        printf("Opción no válida.\n");
    }
}

int main() {
    int sala_asientos[5][4] = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, 
        {13, 14, 15, 16}, {17, 18, 19, 20}
    };

    int ocupados = 0;
    int fila, columna;

    printf("BIENVENIDO AL SISTEMA DE CINE v1.2.1\n");

    while (ocupados < 20) {
        imprimir_sala(sala_asientos);

        printf("\nSelección de Asiento:\n");
        printf("Ingrese Fila (0-4) y Columna (0-3) separados por espacio: ");
        
        if (scanf("%d %d", &fila, &columna) != 2) {
            printf("\n[!] Error: Ingrese números válidos.\n");
            limpiar_buffer();
            continue;
        }

        if (fila >= 0 && fila < 5 && columna >= 0 && columna < 4) {
            if (sala_asientos[fila][columna] == 0) {
                printf("\n[!] El asiento [%d,%d] ya está ocupado. Elija otro.\n", fila, columna);
            } else {
                sala_asientos[fila][columna] = 0;
                ocupados++;
                printf("\n--- Asiento [%d,%d] reservado con éxito ---\n", fila, columna);
                
                comprar_combo();
            }
        } else {
            printf("\n[!] Coordenadas fuera de rango.\n");
        }
    }

    printf("\nSALA LLENA. No hay más asientos disponibles.\n");
    return 0;
}
