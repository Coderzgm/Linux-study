SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
BIN=myprocess

# 编译器换成 g++
CC=g++

$(BIN):$(OBJ)
	$(CC) -o $@ $^

%.o:%.cpp
	$(CC) -c $<

.PHONY: clean
clean:
	rm -f $(OBJ) $(BIN)
