#Autor:Jimmy
#Modificador:Jose Santiago Alegria Ponce
#Fecha 26/marzo/2026
#Versión 1.2.0
#Se agrego un sistema completo de dulceria despues de hacer la compra de boleto
#consiste en un nuevo arreglo como el de los asientos 
#integra sistema de compra y cambio 

def comprar_combo():
    print("--- DULCERÍA ---")
    combos = {
        1: ["Combo Individual (Palomitas + Refresco)", 150],
        2: ["Combo Pareja (Palomitas G + 2 Refrescos)", 280],
        3: ["Combo Familiar (2 Palomitas G + 4 Refrescos + Dulce)", 450]
    }

    for clave, valor in combos.items():
        print(f"{clave}. {valor[0]} - ${valor[1]}")
    
    try:
        opcion = int(input("\nSelecciona el número de combo que deseas (o 0 para saltar): "))
        
        if opcion == 0:
            print("No se agregó combo.\n")
            return

        if opcion in combos:
            nombre_combo = combos[opcion][0]
            precio = combos[opcion][1]
            print(f"Has elegido: {nombre_combo}")
            print(f"Total a pagar: ${precio}")

            pago = float(input("Ingresa la cantidad con la que pagas: $"))

            if pago >= precio:
                cambio = pago - precio
                print(f"Pago exitoso. Tu cambio es: ${cambio:.2f}")
                print("¡Disfruta tu película y tus palomitas!\n")
            else:
                print(f"Dinero insuficiente. Te faltan ${precio - pago:.2f}. No se pudo completar la compra.\n")
        else:
            print("Opción de combo no válida.\n")

    except ValueError:
        print("Error: Ingresa un dato válido para la compra.\n")



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
                    comprar_combo()
            else:
                print("Error: Fila o columna fuera de los límites. Intenta de nuevo.\n")
                
        except ValueError:
            print("Error: Por favor, ingresa solo números enteros.\n")

    print("¡La sala está completamente llena!")

if __name__ == "__main__":
    principal()
