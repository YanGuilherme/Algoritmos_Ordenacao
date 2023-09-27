#include "Selection_sort.h"

SelectionSort::SelectionSort():Algoritmo("selection_sort"){
}

SelectionSort::~SelectionSort(){}

void SelectionSort::ordenar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    for (int i = 0; i < entrada->tamanho - 1; i++) {
    int indiceMinimo = i;
    for (int j = i + 1; j < entrada->tamanho; j++) {
        if (entrada->vector[j] < entrada->vector[indiceMinimo]) {
            indiceMinimo = j;
        }
    }
    int temp = entrada->vector[i];
    entrada->vector[i] = entrada->vector[indiceMinimo];
    entrada->vector[indiceMinimo] = temp;
    }
    double fim = getTempoAtual();
    duracao = fim-inicio;
}
