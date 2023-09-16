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
        void ordenar(DadosEntrada *);
        ~MergeSort();
    private:
        void mergeSort(int*, int*, int , int);
        void merge(int*, int*, int , int , int);
};

#endif