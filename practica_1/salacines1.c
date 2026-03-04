#include <stdio.h>
//Programa sala de cine
// Creador base: Santiago
// Modificador: Antonio
// Version 1.1.0 Minor
// Se realizo algunas mejoras al codigo base.
// Evita que un asiento que ya vale "0" y el feddback avisa si la reserva fue exitosa o fallida.
int main(){
int multiarreglo[5][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
int fila, columna, sala=0;

while(sala < 20){
for(int x=0; x<5; x++){
for(int y=0; y<4; y++){
//Mejora aplicada: un formato mucho mas limpio
printf("[%2i] ", multiarreglo[x][y]);
}
printf("\n");
}

printf("Ingresa fila y columna: ");
scanf("%i %i", &fila, &columna);

fila--; columna--; // Ajuste de los indices

if (fila >= 0 && fila < 5 && columna >= 0 && columna < 4) {
// Mejora aplicada: Verificacion si ya esta ocupado
if(multiarreglo[fila][columna] == 0) {
printf("error: el asiento ya esta ocupado.\n");
} else {
printf("reserva exitosa.\n");
multiarreglo[fila][columna] = 0;
sala++;
}
} else {
printf("error: Fuera de rango.\n");
}
}
}
