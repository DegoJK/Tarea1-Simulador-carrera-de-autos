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
make
```

##Ejecución
Para ejecutar el simulador, debes proporcionar dos argumentos: el número de autos y la distancia total de la carrera en metros. Ejemplo:
```bash
Copiar código
./simulador 5 1000
```
Salida esperada (el progreso variará por la naturaleza aleatoria del programa):
```vbnet
Auto3 avanza 2 metros (total: 78 metros)
Auto1 avanza 2 metros (total: 78 metros)
Auto2 avanza 3 metros (total: 96 metros)
...
Auto2 avanza 6 metros y ha terminado la carrera en el lugar 1!
Auto1 avanza 7 metros (total: 89 metros)
Auto1 avanza 8 metros (total: 97 metros)
Auto3 avanza 5 metros (total: 97 metros)
Auto1 avanza 3 metros y ha terminado la carrera en el lugar 2!
Auto3 avanza 4 metros y ha terminado la carrera en el lugar 3!

..:: ORDEN DE LLEGADA ::..
1. Auto2
2. Auto3
3. Auto1
```

