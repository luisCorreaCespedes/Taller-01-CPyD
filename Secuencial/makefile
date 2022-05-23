CC = g++
OBJ = programaSecuencial.cpp
LIB = 
CPPFLAGS = -Wall

all: $(OBJ)
	@$(CC) $(CPPFLAGS) -o Secuencial $(OBJ)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	$(RM) $(OBJ) Secuencial