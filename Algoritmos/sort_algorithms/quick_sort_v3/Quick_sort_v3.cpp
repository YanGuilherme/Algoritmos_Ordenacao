#include "Quick_sort_v3.h"

QuickSortV3::QuickSortV3() : Algoritmo("quick_sort_v3_pivo_mediana") {}
QuickSortV3::~QuickSortV3() {}

void QuickSortV3::executar(DadosEntrada* entrada) {
    double inicio = getTempoAtual();
    quick_sort_v3(entrada->vector, 0, entrada->get_tamanho());
    double fim = getTempoAtual();
    duracao = fim - inicio;
}

void QuickSortV3::calcularMediana(int* entrada, int* subarray, int tamanho) {
    // Preencher o subarranjo com elementos aleatórios do array original
    for (int k = 0; k < tamanho; k++) {
        int indiceAleatorio = rand() % tamanho; // Gera um índice aleatório
        subarray[k] = entrada[indiceAleatorio];
    }

    insertion_sort(subarray, tamanho);
}

void QuickSortV3::insertion_sort(int* arr, int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = chave;
    }
}

void QuickSortV3::quick_sort_v3(int* entrada, int inicio, int fim) {
    if (inicio < fim) {
        int i, j, pivo, aux;
        int subarray[15];

        calcularMediana(entrada + inicio, subarray, 15);
        pivo = subarray[15 / 2];

        i = inicio;
        j = fim - 1;

        while (i <= j) {
            while (entrada[i] < pivo && i < fim) {
                i++;
            }
            while (entrada[j] > pivo && j > inicio) {
                j--;
            }
            if (i <= j) {
                aux = entrada[i];
                entrada[i] = entrada[j];
                entrada[j] = aux;
                i++;
                j--;
            }
        }

        if (j > inicio)
            quick_sort_v3(entrada, inicio, j + 1);
        if (i < fim)
            quick_sort_v3(entrada, i, fim);
    }
}
