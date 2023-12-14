#include "Merge_sort.h"

MergeSort::~MergeSort()
{
}
MergeSort::MergeSort():Algoritmo("merge_sort"){}


void MergeSort::executar(DadosEntrada* dados){ 
    int* aux = new int[dados->get_tamanho()];
    double inicio = getTempoAtual();
    mergeSort(dados->vector, aux, 0, dados->get_tamanho()-1);
    double fim = getTempoAtual();
    duracao = fim-inicio;
    delete[] aux;

}

void MergeSort::mergeSort(int* entrada, int* auxiliar, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(entrada, auxiliar, inicio, meio);
        mergeSort(entrada, auxiliar, meio + 1, fim);
        merge(entrada, auxiliar, inicio, meio, fim);
    }
}

void MergeSort::merge(int* entrada, int* auxiliar, int inicio, int meio, int fim){
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim){
        if(entrada[i] < entrada[j]){ 
            auxiliar[k] = entrada[i];
            i++;
        }
        else{
            auxiliar[k] = entrada[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        auxiliar[k] = entrada[i];
        i++;
        k++;
    }

    while(j <= fim){
        auxiliar[k] = entrada[j];
        j++;
        k++;
    }

    for(int p = inicio; p <= fim; p++)
        entrada[p] = auxiliar[p];
}

