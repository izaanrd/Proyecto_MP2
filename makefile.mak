# Compilador
CC = g++

# Opciones de compilación
CFLAGS = -c -Wall

# Archivos objeto
OBJ = main_MP_Proyecto_Fase1.o \
Atleta.o \
Atletas.o \
Club.o \
Clubes.o \
Fecha.o \
Inscripcion.o \
Participaciones.o \
Marca.o \
Prueba.o \
Pruebas.o \
Tiempo.o \
utils.o

# Ejecutable
all: programa

programa: $(OBJ)
	$(CC) $(OBJ) -o programa

# Regla genérica
%.o: %.cpp
	$(CC) $(CFLAGS) $<

# Limpieza
clean:
	del *.o *.exe