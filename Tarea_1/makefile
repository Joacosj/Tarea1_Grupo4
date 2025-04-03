# Nombre del ejecutable
TARGET = app1

# Archivos fuente
SRC = main.c metrics.c utils.c

# Archivos objeto
OBJ = main.o metrics.o utils.o

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Regla principal: compilar el ejecutable
$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regla para compilar main.c
main.o: main.c metrics.h utils.h
    $(CC) $(CFLAGS) -c main.c

# Regla para compilar metrics.c
metrics.o: metrics.c metrics.h utils.h
    $(CC) $(CFLAGS) -c metrics.c

# Regla para compilar utils.c
utils.o: utils.c utils.h
    $(CC) $(CFLAGS) -c utils.c

# Regla para limpiar archivos generados
clean:
    rm -f $(OBJ) $(TARGET)
