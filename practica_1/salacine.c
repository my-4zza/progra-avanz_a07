//#Autor: Jose Santiago Alegria Ponce
//#Modificador: Antonio De Jesus Portilla Duran
//#Fecha: 27/marzo/2026
//#Versión: 2.0.0
//Mapa con filas A-E y símbolos . y X  para mejor lectura
//Se integró la Taquilla y Dulcería en un solo pago final
//Ahora permite comprar múltiples combos en la misma sesión
 //Limpieza de pantalla para mantener la consola ordenada

struct Combo {
    char nombre[50];
    float precio;
};

// --- PROTOTIPOS ---
void limpiar_buffer();
void limpiar_pantalla();
void imprimir_sala(int sala[5][4]);
float seleccionar_dulces();
void procesar_pago(float total);

// --- FUNCIONES ---
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void imprimir_sala(int sala[5][4]) {
    printf("\n      Pantalla de cine \n");
    printf("        Col:  0   1   2   3\n");
    printf("       ---------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("Fila %c |", 'A' + i); // Imprime A, B, C, D, E
        for (int j = 0; j < 4; j++) {
            if (sala[i][j] == 0) printf("  X ");
            else printf("  . ");
        }
        printf(" |\n");
    }
    printf("       ---------------------\n");
    printf("      ( . = Libre, X = Ocupado )\n");
}

float seleccionar_dulces() {
    struct Combo combos[3] = {
        {"Combo Individual", 150.0},
        {"Combo Pareja", 280.0},
        {"Combo Familiar", 450.0}
    };
    int opcion, cant;
    float subtotal = 0;

    while (1) {
        printf("\n--- DULCERIA ---\n");
        for (int i = 0; i < 3; i++) {
            printf("%d. %-20s $%.2f\n", i + 1, combos[i].nombre, combos[i].precio);
        }
        printf("0. Finalizar seleccion\n");
        printf("Seleccion: ");

        if (scanf("%d", &opcion) != 1) {
            limpiar_buffer();
            continue;
        }
        if (opcion == 0) break;
        if (opcion >= 1 && opcion <= 3) {
            printf("Cuantos?: ");
            scanf("%d", &cant);
            subtotal += combos[opcion - 1].precio * cant;
            printf("Subtotal actual: $%.2f\n", subtotal);
        }
    }
    limpiar_buffer();
    return subtotal;
}

void procesar_pago(float total) {
    float pago_acumulado = 0, abono;
    printf("\n--- Proceso de pago ---\n");
    printf("Total a pagar: $%.2f\n", total);

    while (pago_acumulado < total) {
        printf("Ingrese pago (Faltan $%.2f): $", total - pago_acumulado);
        if (scanf("%f", &abono) != 1) {
            limpiar_buffer();
            printf("[!] Moneda no valida.\n");
            continue;
        }
        pago_acumulado += abono;
    }
    printf("Pago exitoso Su cambio: $%.2f\n", pago_acumulado - total);
    printf("Presione Enter para continuar");
    limpiar_buffer();
    getchar();
}

int main() {
    int sala[5][4];
    for(int i=0; i<5; i++) for(int j=0; j<4; j++) sala[i][j] = 1;

    int ocupados = 0;
    char fila_letra;
    int col, fila_idx;

    while (ocupados < 20) {
        limpiar_pantalla();
        printf("Sistema de cine v2.0.0\n");
        imprimir_sala(sala);

        printf("\nReserva (Ejemplo: A 2) o 'S' para salir: ");
        char entrada[50];
        fgets(entrada, sizeof(entrada), stdin);

        if (toupper(entrada[0]) == 'S') break;

        if (sscanf(entrada, "%c %d", &fila_letra, &col) == 2) {
            fila_idx = toupper(fila_letra) - 'A';

            if (fila_idx >= 0 && fila_idx < 5 && col >= 0 && col < 4) {
                if (sala[fila_idx][col] == 0) {
                    printf("\n[!] Asiento ocupado. Presione Enter");
                    getchar();
                } else {
                    sala[fila_idx][col] = 0;
                    ocupados++;

                    float t_dulces = seleccionar_dulces();
                    float t_boleto = 65.0;

                    limpiar_pantalla();
                    printf("\n Resumen de compra \n");
                    printf("Asiento %c%d: $%.2f\n", toupper(fila_letra), col, t_boleto);
                    printf("Dulceria:    $%.2f\n", t_dulces);
                    printf("-------------------------\n");
                    procesar_pago(t_boleto + t_dulces);
                }
            } else {
                printf("\n[!] Coordenadas invalidas. Presione Enter");
                getchar();
            }
        }
    }

    printf("\nGracias por usar el sistema v2.0.0\n");
    return 0;
}
