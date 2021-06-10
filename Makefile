CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= /home/eliotanderson/Descargas/SFML-2.5.1/include -I/include
LIB		:= lib

LIBRARIES	:= -L /home/eliotanderson/Descargas/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
