#include "Heap_extract_min.h"
using namespace std;
HeapExtractMin::HeapExtractMin():Algoritmo("heap_extract_min"){}
HeapExtractMin::~HeapExtractMin(){}

void HeapExtractMin::build_min_heap(DadosEntrada *dados)
{
    int heap_size = dados->get_tamanho();
    
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        HeapMin::min_heapify(dados, i, heap_size);
    }
}

int HeapExtractMin::extractMin(DadosEntrada * dados)
{
    if (dados->get_tamanho() <= 0) {
        std::cerr << "Erro: Heap vazio. Impossível extrair mínimo." << std::endl;
        return -1; // Valor de erro
    }

    int menorElemento = dados->vector[0];
    dados->vector[0] =  dados->vector[dados->tamanho - 1];
    dados->tamanho--;
    HeapMin::min_heapify(dados, 0, dados->tamanho);

    return menorElemento;
}

void HeapExtractMin::executar(DadosEntrada* dados){
    double inicio = Algoritmo::getTempoAtual();
    build_min_heap(dados);
    cout <<"--------------------------" << endl;
    cout << "Dados antes da extracao: " << endl; HeapMin::exibir_heap(dados);
    menor = extractMin(dados);
    double fim = Algoritmo::getTempoAtual();
    duracao = fim-inicio;
    cout <<"--------------------------" << endl;
    cout << "Dados depois da extracao: " << endl; HeapMin::exibir_heap(dados);
    cout << "-----> O menor elemento eh: "<< menor <<" <-----" << endl;

}
