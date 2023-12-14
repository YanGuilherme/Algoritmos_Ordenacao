#include "Heap_sort_min.h"
#include "Heap_min.h"

void HeapSortMin::build_min_heap(DadosEntrada* dados) {
    int heap_size = dados->get_tamanho();
    
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        HeapMin::min_heapify(dados, i, heap_size);
    }
}


void HeapSortMin::heapsort(DadosEntrada * dados){
    build_min_heap(dados);
    
    for (int i = dados->get_tamanho() - 1; i > 0; --i) {
        swap(dados->vector[i], dados->vector[0]);
        HeapMin::min_heapify(dados, 0, i);
    }
}

HeapSortMin::HeapSortMin():Algoritmo("heap_sort_min"){}

HeapSortMin::~HeapSortMin(){}

void HeapSortMin::executar(DadosEntrada *dados){
    double inicio = Algoritmo::getTempoAtual();
    HeapSortMin::heapsort(dados);
    double fim = Algoritmo::getTempoAtual();
    duracao = fim-inicio;
}
