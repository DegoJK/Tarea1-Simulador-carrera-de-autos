# Nombre del ejecutable
EXEC = carrera

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++11 -pthread

# Archivos fuente
SRCS = Tarea_SO.cpp

# Objetivo por defecto: compilar el programa
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRCS)

# Regla para limpiar los archivos generados
clean:
	rm -f $(EXEC)
