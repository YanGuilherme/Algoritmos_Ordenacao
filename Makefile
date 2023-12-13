CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O3 -Wl,--stack,67108864
LIBS = 

SRC_DIR = Algoritmos
SRC_FILES = Main.cpp  $(SRC_DIR)/heap_sort/Heap_min.cpp \
			$(SRC_DIR)/heap_sort/Heap_sort_min.cpp \
            DadosEntrada.cpp Arquivo.cpp \
            $(SRC_DIR)/Algoritmo.cpp \


OBJ_FILES = $(SRC_FILES:.cpp=.o)

EXECUTABLE = Main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe /s /q



