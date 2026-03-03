#include <stdio.h>
int main(){
    int multiarreglo[5][4]={{ 1,2,3,4},{5,6,7,8},{9,10,11,12 },{13,14,15,16},{17,18,19,20}};
    int fila,columna,sala=0;

    while(sala<20){
for(int x=0;x<5;x++){
        for(int y=0;y<4;y++){
            printf(" %i",multiarreglo[x][y]);
        }
        printf("\n");
    }
    printf("escoje el asiento\n");
    printf("escribe la fila y columna\n");
    scanf("%i %i",&fila,&columna);
    multiarreglo[fila][columna]=0;

}
}
