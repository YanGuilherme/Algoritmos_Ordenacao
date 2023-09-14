CXX = g++
CXXFLAGS = -Wall -g
LIBS =

SRC_DIR = Algoritmos
SRC_FILES = Main.cpp $(SRC_DIR)/insertion_sort/Insertion_sort.cpp DadosEntrada.cpp Arquivo.cpp  $(SRC_DIR)/Algoritmo.cpp $(SRC_DIR)/bubble_sort/bubble_sort.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

EXECUTABLE = Main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	.\clean.bat



