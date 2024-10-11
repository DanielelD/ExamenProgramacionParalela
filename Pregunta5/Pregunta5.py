import multiprocessing as mp

def calcular_pi_porcion(start, end, step, result, index):
    suma = 0.0
    for i in range(start, end, step):
        termino = (-1) ** i / (2 * i + 1)
        suma += termino
    result[index] = suma

def main():
    num_terminos = 1000000  
    num_procesos = 3  
    step = num_procesos
    result = mp.Array('d', num_procesos)
    procesos = []
    for i in range(num_procesos):
        p = mp.Process(target=calcular_pi_porcion, args=(i, num_terminos, step, result, i))
        procesos.append(p)
        p.start()
    
    for p in procesos:
        p.join()
    pi_aproximado = 4 * sum(result)
    print(f"El valor aproximado de pi con {num_terminos} términos es: {pi_aproximado:.15f}")

if __name__ == "__main__":
    main()
