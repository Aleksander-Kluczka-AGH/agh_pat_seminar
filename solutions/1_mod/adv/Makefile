CXXFLAGS = -std=c++20 -fmodules-ts

SRC = main.cpp mod1.cpp mod2.cpp
OBJ = $(SRC:.cpp=.o)

all: a.out

mod1.o: mod2.o
mod2.o: mod1.o

main.o: mod1.o

a.out: main.o
	$(CXX) $(CXXFLAGS) $(OBJ)

clean:
	rm -rf gcm.cache $(OBJ) a.out

.PHONY: clean