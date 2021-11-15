CXX = g++-11
CXXFLAGS = -std=c++20 -fmodules-ts

SRC = main.cpp sample.cpp
OBJ = $(SRC:.cpp=.o)

all: a.out

main.o: sample.o

a.out: main.o
	$(CXX) $(CXXFLAGS) $(OBJ)

clean:
	rm -rf gcm.cache $(OBJ) a.out

.PHONY: clean