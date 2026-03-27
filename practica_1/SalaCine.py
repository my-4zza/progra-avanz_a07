#Autor:Jimmy
#Modificador:Azael Pérez González
#Fecha 26/marzo/2026
#Versión 1.3.0
#Añade un menú principal con flujo realista (asiento -> dulcería).
#Implementa un cobro unificado (boleto de $65 + combo) y cancela la compra liberando el asiento si el pago es insuficiente.
#Mejora visual marcando los lugares ocupados con [X].

def comprar_combo():
    print("\n--- DULCERÍA ---")
    combos = {
        1: ["Combo Individual (Palomitas + Refresco)", 150],
        2: ["Combo Pareja (Palomitas G + 2 Refrescos)", 280],
        3: ["Combo Familiar (2 Palomitas G + 4 Refrescos + Dulce)", 450]
    }
    for clave, valor in combos.items():
        print(f"{clave}. {valor[0]} - ${valor[1]}")
    try:
        opcion = int(input("\nSelecciona el número de combo que deseas (o 0 para no llevar comida): "))
        if opcion == 0:
            print("Continuando sin combo...\n")
            return "Ninguno", 0
        if opcion in combos:
            nombre_combo = combos[opcion][0]
            precio = combos[opcion][1]
            print(f"Has agregado al carrito: {nombre_combo}")
            return nombre_combo, precio
        else:
            print("Opción no válida. Continuando sin combo...\n")
            return "Ninguno", 0
    except ValueError:
        print("Error: Ingreso no válido. Continuando sin combo...\n")
        return "Ninguno", 0

def principal():
    multiarreglo = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16],
        [17, 18, 19, 20]
    ]
    sala = 0 
    precio_boleto = 65
    while True:
        print("\n========== CINE ==========")
        print("1. Entrar a ver la sala")
        print("2. Salir del sistema")
        print("==========================")
        try:
            opcion_menu = int(input("Elige una opción: "))
            if opcion_menu == 1:
                print("\n--- PANTALLA ---")
                for incognita in range(5):
                    for y in range(4):
                        # Se usa la X para los ocupados
                        if multiarreglo[incognita][y] == 'X':
                            print(" [ X]", end=" ")
                        else:
                            print(f" [{multiarreglo[incognita][y]:2}]", end=" ") 
                    print("\n")
                # Validación de asientos disponibles
                if sala >= 20:
                    print("No hay asientos disponibles, disculpa.\n")
                else:
                    print("Escoge tu asiento")
                    try:
                        fila = int(input("Fila (0-4): "))
                        columna = int(input("Columna (0-3): "))
                        if 0 <= fila < 5 and 0 <= columna < 4:
                            if multiarreglo[fila][columna] == 'X':
                                print("¡Ese asiento ya está ocupado! Operación cancelada.\n")
                            else:
                                # Se guarda el número original por si la compra falla
                                asiento_numero = multiarreglo[fila][columna]
                                multiarreglo[fila][columna] = 'X'
                                sala += 1 
                                print("\n¡Asiento apartado con éxito!")
                                # El flujo continúa automáticamente hacia la comida
                                combo_elegido, precio_combo = comprar_combo()
                                # Generación de ticket y cobro unificado
                                total_a_pagar = precio_boleto + precio_combo
                                print("\n" + "="*35)
                                print("          RECIBO DE COMPRA")
                                print("="*35)
                                print(f"Asiento: Fila {fila}, Columna {columna} (Num {asiento_numero})")
                                print(f"Costo Boleto: ${precio_boleto}")
                                print(f"Dulcería: {combo_elegido} - ${precio_combo}")
                                print("-" * 35)
                                print(f"TOTAL A PAGAR: ${total_a_pagar}")
                                print("="*35)
                                pago = float(input("\nIngresa la cantidad con la que pagas: $"))
                                if pago >= total_a_pagar:
                                    print(f"\nPago exitoso. Tu cambio es: ${pago - total_a_pagar:.2f}")
                                    print("¡Disfruta tu película!\n")
                                else:
                                    print(f"\nDinero insuficiente. Se ha cancelado la compra.")
                                    # Si no le alcanza, le quitamos el asiento para que alguien más lo compre
                                    multiarreglo[fila][columna] = asiento_numero
                                    sala -= 1
                        else:
                            print("Error: Fila o columna fuera de los límites.\n")
                    except ValueError:
                        print("Error: Por favor, ingresa solo números enteros.\n")
            elif opcion_menu == 2:
                print("\nSaliendo del sistema... ¡Gracias por tu visita!")
                break
            else:
                print("\nOpción no válida. Por favor, elige 1 o 2.\n")
        except ValueError:
            print("\nError: Por favor, ingresa un número del menú.\n")
if __name__ == "__main__":
    principal()
