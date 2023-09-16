#include "Merge_sort.h"

//nao prontaaaaaaaaaaaaa

MergeSort::~MergeSort()
{
}
MergeSort::MergeSort():Algoritmo("merge_sort"){}

void merge(int *saida, int *auxiliar, int inicio, int meio, int fim){
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = inicio;
    while(i <= meio && j <= fim){
        if(auxiliar[i] < auxiliar[j]){
            saida[k] = auxiliar[i];
            i++;
        }
        else{
            saida[k] = auxiliar[j];
            j++;
        }
        k++;
    }

    while(i <= meio){
        saida[k] = auxiliar[i];
        i++;
        k++;
    }

    while(j <= fim){
        saida[k] = auxiliar[j];
        j++;
        k++;
}
//Copia os elementos que foram ordenados para o auxiliar
for(int p = inicio; p <= fim; p++)
    auxiliar[p] = saida [p];
}

void MergeSort::ordenar(int* entrada, int* auxiliar, int inicio, int fim){
    
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        ordenar(entrada, auxiliar, inicio, meio);
        ordenar(entrada, auxiliar, meio + 1, fim);
        merge(entrada, auxiliar, inicio, meio, fim);
    }
}

