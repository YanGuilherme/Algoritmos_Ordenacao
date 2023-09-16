#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

//nao prontaaaaaaaaa
class MergeSort: public Algoritmo{
    MergeSort();
    ~MergeSort();
    void ordenar(int*, int*,int,int);
    int* aux;
    int inicio, fim;
};

#endif