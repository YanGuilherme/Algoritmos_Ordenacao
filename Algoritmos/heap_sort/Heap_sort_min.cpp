#include "Heap_sort_min.h"
#include "Heap_min.h"


void HeapSortMin::heapsort(DadosEntrada * dados){
    HeapMin::build_min_heap(dados);
    int metade = dados->get_tamanho()/2;
    // int heap_size = dados->get_tamanho();
    
    for (int i = dados->get_tamanho() - 1; i > 0; --i) {
        swap(dados->vector[i], dados->vector[0]);
        HeapMin::min_heapify(dados, 0, i);
    }
    for (int i = 0; i < metade; ++i) { // Invertendo os valores :D  
       swap(dados->vector[i], dados->vector[dados->get_tamanho() - 1 - i]);
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
