CC = g++
OBJ = programaOMP.cpp
LIB = -fopenmp
CPPFLAGS = -Wall

all: $(OBJ)
	@$(CC) $(CPPFLAGS) -o OpenMP $(OBJ)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	$(RM) $(OBJ) OpenMP