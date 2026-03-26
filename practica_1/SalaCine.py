#Programa sala de cines
#Autor:Jimmy
#Modificador:Jose Santiago Alegria Ponce
#Fecha 3/10/2026
#Versión 1.1.0
#Se agrego un bucle if para que no se puedan poner filas o columnas no permitidas 

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
               
                print(f" {multiarreglo[incognita][y]:2}", end=" ") 
            print("\n")
        
        print("Escoge el asiento")
        print("Escribe la fila (0-4) y columna (0-3)")
        
        try:
            fila = int(input("Fila: "))
            columna = int(input("Columna: "))
            
            if 0 <= fila < 5 and 0 <= columna < 4:
          
                if multiarreglo[fila][columna] == 0:
                    print("¡Ese asiento ya está ocupado! Por favor elige otro.\n")
                else:
                    multiarreglo[fila][columna] = 0
                    sala += 1 
                    print("¡Asiento reservado con éxito!\n")
            else:
                print("Error: Fila o columna fuera de los límites. Intenta de nuevo.\n")
                
        except ValueError:
            print("Error: Por favor, ingresa solo números enteros.\n")

    print("¡La sala está completamente llena!")

if __name__ == "__main__":
    principal()
