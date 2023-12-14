#include "Heap_increase_key.h"

void MaxIncreaseKey::executar(DadosEntrada* dados){
    double inicio = Algoritmo::getTempoAtual();
    build_min_heap(dados);
    double fim = Algoritmo::getTempoAtual();
    duracao = fim-inicio;
    increase_key(dados);
}

void MaxIncreaseKey::build_min_heap(DadosEntrada* dados){
    int heap_size = dados->get_tamanho();
    
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        HeapMin::min_heapify(dados, i, heap_size);
    }
}

MaxIncreaseKey::MaxIncreaseKey():Algoritmo("max_increase_key"){}

MaxIncreaseKey::~MaxIncreaseKey(){}

void MaxIncreaseKey::increase_key(DadosEntrada *dados){
    int escolha;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Valor entre 0 e " << dados->get_tamanho() << endl;
    cout << "Digite a posicao que deseja inserir: ";
    cin >> escolha;
    dados->vector[escolha-1] = 1000;

}
