#Programa sala de cines
#Autor:Jimmy
#Modificador:Alfredo
#Versión 1.0.1
#Se agrego sala += 1 para que no se haga un bucle
def principal():
    multiarreglo = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16],
        [17, 18, 19, 20]
    ]
    
    sala = 0 
    
    while sala < 20:
        for incognita in range(5):
            for y in range(4):
                print(f" {multiarreglo[incognita][y]:2}", end="")
            print("")
        
        print("\nEscoge el asiento")
        print("Escribe la fila (0-4) y columna (0-3)")
        
        fila = int(input("Fila: "))
        columna = int(input("Columna: "))
        if multiarreglo[fila][columna] != 0:
            multiarreglo[fila][columna] = 0
            sala += 1 
            print("--- Asiento reservado con éxito ---\n")
        else:
            print("--- Ese asiento ya está ocupado ---\n")

if __name__ == "__main__":
    principal()
