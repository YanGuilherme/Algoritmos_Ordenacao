#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class MergeSort: public Algoritmo{
    public:
        MergeSort();
        void ordenar(DadosEntrada *dados);
        void mergeSort(int *entrada, int *auxiliar, int inicio, int fim);
        void merge(int *entrada, int *auxiliar, int inicio, int meio, int fim);
        ~MergeSort();
};

#endif