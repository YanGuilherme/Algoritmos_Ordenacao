#include "Bubble_sort.h"

BubbleSort::BubbleSort():Algoritmo("bubble_sort"){}

BubbleSort::~BubbleSort()
{}

void BubbleSort::ordenar(DadosEntrada* entrada){
    // loop to access each array element
    double inicio = getTempoAtual();
    bool trocou;
    for (int i = 0; i < entrada->tamanho - 1; i++) {
        trocou = false;

        for (int j = 0; j < entrada->tamanho - i - 1; j++) {
            if (entrada->vector[j] > entrada->vector[j + 1]) {
                // Troca os elementos arr[j] e arr[j + 1]
                int temp = entrada->vector[j];
                entrada->vector[j] = entrada->vector[j + 1];
                entrada->vector[j + 1] = temp;

                trocou = true;
            }
        }

        // Se durante a passagem interna não houve trocas, o array está ordenado
        if (!trocou) {
            break;
        }
    }
    double fim = getTempoAtual();
    duracao = fim-inicio;
}

