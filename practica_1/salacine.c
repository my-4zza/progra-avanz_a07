//#Autor: Jose Santiago Alegria Ponce
//#Modificador: Azael Pérez González
//#Fecha: 27/marzo/2026
//#Versión: 1.3.0
// Se añadió el módulo de Taquilla.
// Se mejoró la validación de asientos (fgets/sscanf) para forzar el ingreso de
// coordenadas en una sola línea y evitar que el mapa se reimprima tras un error de formato.

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
void cobrar_taquilla();
void comprar_combo();

// --- FUNCIONES ---
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void imprimir_sala(int sala[5][4]) {
    printf("\n      --- MAPA DE LA SALA ---\n");
    printf("      Col:  0   1   2   3\n"); 
    printf("     --------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Fila %d |", i); 
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

void cobrar_taquilla() {
    float precio_boleto = 65.0; 
    float pago = 0;

    printf("\n--- TAQUILLA ---\n");
    printf("Total a pagar por boleto: $%.2f\n", precio_boleto);

    while (pago < precio_boleto) {
        float abono;
        printf("Ingrese pago (Faltan $%.2f): $", precio_boleto - pago);
        if (scanf("%f", &abono) != 1) {
            limpiar_buffer();
            printf("Error en moneda. Reintente.\n");
            continue;
        }
        pago += abono;
        
        if (pago < precio_boleto) {
            printf("Aún no es suficiente.\n");
        }
    }
    
    limpiar_buffer(); 
    printf("¡Pago de taquilla exitoso! Su cambio: $%.2f\n", pago - precio_boleto);
}

void comprar_combo() {
    struct Combo combos[3] = {
        {"Combo Individual (Palomitas + Refresco)", 150.0},
        {"Combo Pareja (2 Refrescos + Palomitas G)", 280.0},
        {"Combo Familiar (4 Refrescos + 2 Palomitas G)", 450.0}
    };

    printf("\n--- DULCERÍA ---\n");
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
    
    limpiar_buffer(); 

    if (opcion == 0) return;
    if (opcion >= 1 && opcion <= 3) {
        float precio = combos[opcion - 1].precio;
        float pago = 0;

        printf("Total: $%.2f\n", precio);
        
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
        
        limpiar_buffer(); 
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
    char entrada_usuario[50]; 

    printf("BIENVENIDO AL SISTEMA DE CINE v1.3.3\n");

    while (ocupados < 20) {
        imprimir_sala(sala_asientos);
        printf("\nSelección de Asiento:\n");
        bool formato_correcto = false;
    
        // Bucle interno para atrapar errores de formato sin reimprimir el mapa
        while (!formato_correcto) {
            printf("Ingrese Fila (0-4) y Columna (0-3) en la misma línea (ej. 2 3): ");
            
            if (fgets(entrada_usuario, sizeof(entrada_usuario), stdin) != NULL) {
                char caracteres_extra;
                int campos_leidos = sscanf(entrada_usuario, "%d %d %c", &fila, &columna, &caracteres_extra);
                
                if (campos_leidos < 2 || (campos_leidos == 3 && caracteres_extra != '\n' && caracteres_extra != ' ')) {
                    printf("[!] Formato incorrecto. Deben ser dos números separados por un espacio.\n");
                } else {
                    formato_correcto = true; // Salimos del bucle interno
                }
            }
        }

        // Una vez que el formato es válido, revisamos que las coordenadas existan y estén libres
        if (fila >= 0 && fila < 5 && columna >= 0 && columna < 4) {
            if (sala_asientos[fila][columna] == 0) {
                printf("\n[!] El asiento [%d,%d] ya está ocupado. Elija otro.\n", fila, columna);
            } else {
                sala_asientos[fila][columna] = 0;
                ocupados++;
                printf("\n--- Asiento [%d,%d] reservado con éxito ---\n", fila, columna);
                
                cobrar_taquilla();
                comprar_combo();
            }
        } else {
            // Si metieron coordenadas como 8 9, les avisa y vuelve a imprimir el mapa
            printf("\n[!] Coordenadas fuera de rango. Recuerde: Fila (0-4) y Columna (0-3).\n");
        }
    }

    printf("\nSALA LLENA. No hay más asientos disponibles.\n");
    return 0;
}
