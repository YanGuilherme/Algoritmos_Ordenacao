CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O3 -Wl,--stack,67108864
LIBS = 

SRC_DIR = Algoritmos
SRC_FILES = Main.cpp  $(SRC_DIR)/heap_sort/Heap_min.cpp \
			$(SRC_DIR)/heap_sort/Heap_sort_min.cpp \
			$(SRC_DIR)/heap_sort/Heap_minimum.cpp \
			$(SRC_DIR)/heap_sort/Heap_extract_min.cpp \
			$(SRC_DIR)/heap_sort/Heap_increase_key.cpp \
			$(SRC_DIR)/heap_sort/Max_heap_insert.cpp \
            $(SRC_DIR)/sort_algorithms/shell_sort/Shell_sort.cpp \
			$(SRC_DIR)/sort_algorithms/quick_sort_v1/Quick_Sort_v1.cpp \
			$(SRC_DIR)/sort_algorithms/quick_sort_v2/Quick_Sort_v2.cpp \
            $(SRC_DIR)/sort_algorithms/quick_sort_v3/Quick_sort_v3.cpp \
            $(SRC_DIR)/sort_algorithms/quick_sort_v4/Quick_sort_v4.cpp \
			$(SRC_DIR)/sort_algorithms/bubble_sortv1/Bubble_sortv1.cpp\
			$(SRC_DIR)/sort_algorithms/bubble_sortv2/Bubble_sortv2.cpp\
			$(SRC_DIR)/sort_algorithms/insertion_sort/Insertion_sort.cpp \
			$(SRC_DIR)/sort_algorithms/selection_sort/Selection_sort.cpp \
			$(SRC_DIR)/sort_algorithms/merge_sort/Merge_sort.cpp \
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



