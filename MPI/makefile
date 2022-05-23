CC = g++
OBJ = programaMPI.cpp
LIB = -l -lmpi
CPPFLAGS = -Wall

all: $(OBJ)
	@$(CC) $(CPPFLAGS) -o MPI $(OBJ)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	$(RM) $(OBJ) MPI