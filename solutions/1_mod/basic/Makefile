CXXFLAGS = -std=c++20 -fmodules-ts

SRC = main.cpp printer.cpp
OBJ = $(SRC:.cpp=.o)

all: a.out

main.o: printer.o

a.out: main.o
	$(CXX) $(CXXFLAGS) $(OBJ)

clean:
	rm -rf gcm.cache $(OBJ) a.out

.PHONY: clean