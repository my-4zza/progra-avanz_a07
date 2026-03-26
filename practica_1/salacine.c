#include <stdio.h>
//Programa sala de cine
//autor: Santiago
// modificador: Alfredo
// versión 1.0.1
// se agrego sala++ para evitar un bucle infinito
int main(){
    int multiarreglo[5][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int fila, columna, sala=0;
    int x,y;
    while(sala < 20){
        for( x=0; x<5; x++){
            for(y=0; y<4; y++){
                printf(" %i", multiarreglo[x][y]);
            }
            printf("\n");
        }
        printf("Escoje el asiento (Fila 1-5, Columna 1-4): \n");
        scanf("%i %i", &fila, &columna);
        fila = fila - 1; 
        columna = columna - 1;
        if (fila >= 0 && fila < 5 && columna >= 0 && columna < 4) {
            multiarreglo[fila][columna] = 0;
            sala++; 
        } else {
            printf("Error: Coordenadas invalidas.\n");
        }
    }
}
