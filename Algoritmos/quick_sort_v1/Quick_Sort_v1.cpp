#include "Quick_Sort_v1.h"
#include <stack> 

void QuickSortV1::troca(int* vector, int a, int b) {
    int temp = vector[a];
    vector[a] = vector[b];
    vector[b] = temp;
}

int QuickSortV1::particao(int* vector, int p, int r) {
    int q = vector[p]; // Pivô é o primeiro elemento do vetor
    int i = p + 1;
    int j = r;

    while (true) {
        while (i <= j && vector[i] <= q) {
            i++;
        }
        while (j >= i && vector[j] >= q) {
            j--;
        }
        if (i < j) {
            troca(vector, i, j);
        } else {
            break;
        }
    }
    troca(vector, p, j); // Coloca o pivô na posição correta
    return j; // Retorna a posição do pivô
}

void QuickSortV1::quick_sortv1(int* vector, int p, int r) {
    std::stack<std::pair<int, int>> stack;
    stack.push(std::make_pair(p, r));

    while (!stack.empty()) {
        std::pair<int, int> current = stack.top();
        stack.pop();
        int p = current.first;
        int r = current.second;

        if (p < r) {
            int pivotIndex = particao(vector, p, r);
            stack.push(std::make_pair(p, pivotIndex - 1));
            stack.push(std::make_pair(pivotIndex + 1, r));
        }
    }
}

void QuickSortV1::ordenar(DadosEntrada* dados) {
    double inicio = getTempoAtual();
    quick_sortv1(dados->vector, 0, dados->get_tamanho() - 1);
    double fim = getTempoAtual();
    duracao = fim - inicio;
}

QuickSortV1::QuickSortV1() : Algoritmo("quick_sortv1") {}

QuickSortV1::~QuickSortV1() {}
