CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDFLAGS = 
SRC = main.cpp gpa.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = gpacalc

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean