#Autor:Jimmy
#Modificador:Antonio De Jesus Portilla Duran. |
#Fecha 26/marzo/2026
#Versión 2.0.0
#Mapa visual con . y libre y X usando filas A-E.
#Ahora permite comprar varios productos y cantidades a la vez.
#Calcula el total sumando el asiento + todos los dulces comprados.
#Limpieza de pantalla automática y mejor manejo de errores.
import os

def limpiar_pantalla():
    os.system('cls' if os.name == 'nt' else 'clear')

def mostrar_sala(asientos):
    print("\n      --- Pantalla de interfaz ---")
    print("     0   1   2   3") # Columnas
    filas_letras = ["A", "B", "C", "D", "E"]
    for i, fila in enumerate(asientos):
        print(f"{filas_letras[i]} |", end="")
        for asiento in fila:
            # Si el valor es 0, mostramos 'X' (Ocupado), si no, '.' (Libre)
            char = " X " if asiento == 0 else " . "
            print(char, end="|")
        print()
    print("\n(. = Libre, X = Ocupado)")

def comprar_dulceria():
    total_dulceria = 0
    combos = {
        1: ["Combo individual", 150],
        2: ["Combo pareja", 280],
        3: ["Combo familiar", 450]
    }

    while True:
        print("\n--- Tienda de dulces ---")
        for k, v in combos.items():
            print(f"{k}. {v[0]} (${v[1]})")
        print("0. Finalizar compra de dulces")
        
        try:
            op = int(input("Selecciona una opción: "))
            if op == 0: break
            if op in combos:
                cant = int(input(f"¿Cuántos '{combos[op][0]}' deseas?: "))
                total_dulceria += combos[op][1] * cant
                print(f"Agregado. Subtotal: ${total_dulceria}")
            else:
                print("Opción no válida.")
        except ValueError:
            print("Entrada inválida.")
    
    return total_dulceria

def principal():
    # Inicializamos sala (1 = disponible)
    sala = [[1 for _ in range(4)] for _ in range(5)]
    asientos_ocupados = 0
    total_asientos = 20
    letras_a_indice = {"A": 0, "B": 1, "C": 2, "D": 3, "E": 4}

    while asientos_ocupados < total_asientos:
        limpiar_pantalla()
        mostrar_sala(sala)
        
        print(f"\nAsientos disponibles: {total_asientos - asientos_ocupados}")
        try:
            fila_input = input("Escoge fila (A-E) o 'S' para salir: ").upper()
            if fila_input == 'S': break
            
            columna = int(input("Escoge columna (0-3): "))
            fila = letras_a_indice.get(fila_input)

            if fila is not None and 0 <= columna < 4:
                if sala[fila][columna] == 0:
                    print("Asiento ya ocupado")
                    input("Presiona enter para continua")
                else:
                    sala[fila][columna] = 0
                    asientos_ocupados += 1
                    print("\n¡Asiento reservado!")
                    
                    # Proceso de pago
                    costo_dulces = comprar_dulceria()
                    costo_asiento = 80 # Precio base por asiento
                    total_final = costo_asiento + costo_dulces
                    
                    print(f"\n--- ticket de compra ---")
                    print(f"Asiento {fila_input}{columna}: ${costo_asiento}")
                    print(f"Dulcería: ${costo_dulces}")
                    print(f"Total: ${total_final}")
                    input("\nPresiona Enter para el siguiente cliente...")
            else:
                print("Coordenadas no validas.")
                input("Intenta de nuevo")

        except (ValueError, KeyError):
            print("Error en los datos ingresados.")
            input("Presiona enter")

    print("Cierre de sistema. Sala llena o proceso terminado")

if __name__ == "__main__":
    principal()
