#include "Quick_Sort_v2.h"
#include <stack>

using namespace std;

void QuickSortV2::troca(int* vector, int a, int b) {
    int temp = vector[a];
    vector[a] = vector[b];
    vector[b] = temp;
}

long QuickSortV2::calcularMedia(int* vector, int inicio, int fim) {
    long soma = 0;
    for (int i = inicio; i <= fim; i++) {
        soma += vector[i];
    }
    return soma / (fim - inicio + 1);
}

int QuickSortV2::particao(int* vector, int p, int r) {
    int pivot = calcularMedia(vector, p, r); // Pivô é a média dos elementos
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (vector[j] < pivot) {
            i++;
            troca(vector,i,j);
        }
    }

    troca(vector,i + 1, r);
    return i + 1;
}

void QuickSortV2::quick_sortv2(int* vector, int p, int r) {
    if (p < r) {
        int indicePivo = particao(vector, p, r);
        quick_sortv2(vector, p, indicePivo - 1);
        quick_sortv2(vector, indicePivo + 1, r);
    }
}



void QuickSortV2::ordenar(DadosEntrada* dados) {
    double inicio = getTempoAtual();
    quick_sortv2(dados->vector, 0, dados->get_tamanho() - 1);
    double fim = getTempoAtual();
    duracao = fim - inicio;
}

QuickSortV2::QuickSortV2() : Algoritmo("quick_sortv2") {}

QuickSortV2::~QuickSortV2() {}
