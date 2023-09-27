#include "Bubble_sortv1.h"

BubbleSortv1::BubbleSortv1():Algoritmo("bubble_sortv1_nao_otimizado"){}

BubbleSortv1::~BubbleSortv1(){}

void BubbleSortv1::ordenar(DadosEntrada* entrada){
    double inicio = getTempoAtual();
    for (int i = 0; i < entrada->tamanho - 1; i++) {
        for (int j = 0; j < entrada->tamanho - i - 1; j++) {
            if (entrada->vector[j] > entrada->vector[j + 1]) {
                int temp = entrada->vector[j];
                entrada->vector[j] = entrada->vector[j + 1];
                entrada->vector[j + 1] = temp;
            }
        }
    }
    double fim = getTempoAtual();
    duracao = fim-inicio;
}

