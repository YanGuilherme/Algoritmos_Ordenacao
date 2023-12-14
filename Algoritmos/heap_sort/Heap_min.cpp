#include "Heap_min.h"

HeapMin::HeapMin(){}

HeapMin::~HeapMin(){}



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


void HeapMin::exibir_heap(DadosEntrada* dados) {
    for (int i = 0; i < dados->get_tamanho(); i++) {
        cout << dados->vector[i] << " ";
    }
    cout << endl;
}


