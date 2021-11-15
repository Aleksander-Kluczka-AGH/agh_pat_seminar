CXX = g++-11
CXXFLAGS = -std=c++20 -fmodules-ts

SRC = main.cpp dep.cpp dep_A.cpp dep_B.cpp
OBJ = $(SRC:.cpp=.o)

all: a.out

dep_A.o: dep_B.o
dep.o: dep_A.o
main.o: dep.o

a.out: main.o
	$(CXX) $(CXXFLAGS) $(OBJ)

clean:
	rm -rf gcm.cache $(OBJ) a.out

.PHONY: clean