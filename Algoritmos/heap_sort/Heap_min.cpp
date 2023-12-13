#include "Heap_min.h"

HeapMin::HeapMin(){}

HeapMin::~HeapMin(){}

void HeapMin::build_min_heap(DadosEntrada* dados) {
    int heap_size = dados->get_tamanho();
    
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        HeapMin::min_heapify(dados, i, heap_size);
    }
}

void HeapMin::min_heapify(DadosEntrada* dados, int i, int heap_size) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left < heap_size && dados->vector[left] < dados->vector[smallest]) {
        smallest = left;
    }

    if (right < heap_size && dados->vector[right] < dados->vector[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(dados->vector[i], dados->vector[smallest]);
        HeapMin::min_heapify(dados, smallest, heap_size);
    }
}


