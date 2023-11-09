#include "Quick_Sort_v2.h"
#include <stack>

using namespace std;

void QuickSortV2::troca(int* vector, int a, int b) {
    int temp = vector[a];
    vector[a] = vector[b];
    vector[b] = temp;
}

double QuickSortV2::calcularMedia(int* vector, int inicio, int fim) {
    long soma = 0;
    for (int i = inicio; i <= fim; i++) {
        soma += vector[i];
    }
    return static_cast<double>(soma) / (fim - inicio + 1);
}


int QuickSortV2::particao(int* vector, int p, int r) {
    // Calcular a média global
    double mediaGlobal = calcularMedia(vector, p, r);

    // Encontrar elemento próximo à média para ser usado como pivô
    int indicePivo = p;
    double diffMin = abs(vector[p] - mediaGlobal);

    for (int i = p + 1; i <= r; i++) {
        double diffAtual = abs(vector[i] - mediaGlobal);
        if (diffAtual < diffMin) {
            diffMin = diffAtual;
            indicePivo = i;
        }
    }

    // Trocar o pivô com o último elemento
    troca(vector, indicePivo, r);

    // Partição similar ao original
    int pivot = vector[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (vector[j] < pivot) {
            i++;
            troca(vector, i, j);
        }
    }

    troca(vector, i + 1, r);
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
