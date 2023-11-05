CXX = g++
CXXFLAGS = -Wall -g
LIBS = 

SRC_DIR = Algoritmos
SRC_FILES = Main.cpp  $(SRC_DIR)/merge_sort/Merge_sort.cpp \
            $(SRC_DIR)/quick_sort/Quick_sort.cpp \
            $(SRC_DIR)/insertion_sort/Insertion_sort.cpp \
            DadosEntrada.cpp Arquivo.cpp \
            $(SRC_DIR)/shell_sort/Shell_sort.cpp \
            $(SRC_DIR)/selection_sort/Selection_sort.cpp \
            $(SRC_DIR)/Algoritmo.cpp \
            $(SRC_DIR)/bubble_sortv1/bubble_sortv1.cpp \
            $(SRC_DIR)/bubble_sortv2/bubble_sortv2.cpp \
			$(SRC_DIR)/quick_sort_v1/Quick_Sort_v1.cpp \
			$(SRC_DIR)/quick_sort_v2/Quick_Sort_v2.cpp



OBJ_FILES = $(SRC_FILES:.cpp=.o)

EXECUTABLE = Main.exe

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe /s /q



