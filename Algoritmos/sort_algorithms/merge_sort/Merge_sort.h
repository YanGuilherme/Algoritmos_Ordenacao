#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class MergeSort: public Algoritmo{
    public:
        MergeSort();
        void executar(DadosEntrada *);
        ~MergeSort();
    private:
        void mergeSort(int*, int*, int , int);
        void merge(int*, int*, int , int , int);
};

#endif