CC = g++
CDFLAGS = -Wall -g
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=%.o)
EXE = AVLTree

all: $(EXE)
	@echo Done!
	@echo
	@echo Usage: ./$(EXE)

$(EXE): $(OBJ)
	@echo Linking...
	@$(CC) $(OBJ) -o $@

$(OBJ): $(SRC)
	@echo Compiling...
	@$(CC) $(CDFLAGS) -c $(SRC) $<

clean:
	@echo Cleaning up...
	@rm -f *.o
	@rm -f *.core
	@rm -f *.out
	@rm -f $(EXE)
