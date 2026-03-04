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

                print(f" {multiarreglo[incognita][y]}", end="")
 
            print("\n")
        
        print("escoje el asiento")
        print("escribe la fila y columna")
        
        fila = int(input("Fila: "))
        columna = int(input("Columna: "))
        
        multiarreglo[fila][columna] = 0

if __name__ == "__main__":
    principal()
