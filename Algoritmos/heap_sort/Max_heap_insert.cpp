#include "Max_heap_insert.h"

MaxHeapInsert::MaxHeapInsert():Algoritmo("max_heap_insert"){

}

MaxHeapInsert::~MaxHeapInsert(){}

void MaxHeapInsert::executar(DadosEntrada* dados){
    double inicio = Algoritmo::getTempoAtual();
    build_min_heap(dados);
    double fim = Algoritmo::getTempoAtual();
    duracao = fim - inicio;

}

void MaxHeapInsert::build_min_heap(DadosEntrada* dados){
    int heap_size = dados->get_tamanho();
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        HeapMin::min_heapify(dados, i, heap_size);
    }
    dados->vector[0] = 1000;
    HeapMin::min_heapify(dados, 0, heap_size);

}
