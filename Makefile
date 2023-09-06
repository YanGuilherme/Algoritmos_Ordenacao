CXX = g++
CXXFLAGS = -Wall -g
LIBS =

SRC_DIR = insertion_sort
SRC_FILES = Main.cpp $(SRC_DIR)/Insertion_sort.cpp DadosEntrada.cpp Arquivo.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

EXECUTABLE = Main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@




