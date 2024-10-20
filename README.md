# Tarea1-Simulador-carrera-de-autos.
Este proyecto es un simulador de carrera de autos utilizando hilos en C++. Cada auto es representado por un hilo separado, y la carrera se simula avanzando de manera aleatoria a lo largo de una distancia definida. La velocidad y la distancia recorrida por los autos se calculan de forma aleatoria en cada iteración.

## Funcionalidades
- Cada automóvil tiene un identificador único (Auto1, Auto2, etc.).
- Los autos avanzan una cantidad aleatoria de metros (máximo 10 metros por iteración).
- La velocidad de los autos varía aleatoriamente en cada iteración (deteniéndose entre 100 y 500 ms).
- La carrera finaliza cuando todos los autos han cruzado la meta.
- Muestra el progreso de cada auto en tiempo real en la terminal.
- El ganador y el orden de llegada se muestran al final de la carrera.

## Requisitos

- Compilador C++ con soporte para C++11 o superior.
  
## Instrucciones para Compilar y Ejecutar

### Compilación en Linux/MacOS (con Makefile)
Si estás en Linux o MacOS, puedes compilar el programa utilizando el `Makefile` incluido. Asegúrate de estar en el directorio raíz del proyecto y ejecuta:
```bash
make clean
```

##Ejecución
Para ejecutar el simulador, debes proporcionar dos argumentos: el número de autos y la distancia total de la carrera en metros. Ejemplo:
```bash
Copiar código
./simulador 5 1000
```
Salida esperada (el progreso variará por la naturaleza aleatoria del programa):
```vbnet
Auto 1 ha avanzado 30 metros
Auto 2 ha avanzado 45 metros
Auto 3 ha avanzado 40 metros
...
Auto 2 ha llegado a la meta
Auto 3 ha llegado a la meta
Auto 1 ha llegado a la meta

Orden de llegada:
1. Auto 2
2. Auto 3
3. Auto 1
```

