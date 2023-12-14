#include "Heap_minimum.h"
using namespace std;



HeapMinimum::HeapMinimum():Algoritmo("show_minimum_heap"){}

HeapMinimum::~HeapMinimum(){}

void HeapMinimum::build_min_heap(DadosEntrada* dados) {
    int heap_size = dados->get_tamanho();
    
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        HeapMin::min_heapify(dados, i, heap_size);
    }
    menor = dados->vector[0];
}





void HeapMinimum::executar(DadosEntrada *dados){
    double inicio = Algoritmo::getTempoAtual();
    build_min_heap(dados);
    double fim = Algoritmo::getTempoAtual();
    duracao = fim-inicio;
    HeapMin::exibir_heap(dados);
    cout << "-----> O menor elemento eh: "<< menor <<" <-----" << endl;
}

