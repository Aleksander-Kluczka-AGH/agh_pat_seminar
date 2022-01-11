CXXFLAGS = -std=c++20

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: a.out

a.out: main.o
	$(CXX) $(CXXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ) a.out

.PHONY: clean