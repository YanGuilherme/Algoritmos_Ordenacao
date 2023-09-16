#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class QuickSort: public Algoritmo{
    public:
        QuickSort();
        ~QuickSort();
        void ordenar(DadosEntrada*);
    private:
        void quick_sort(int*, int, int);
};
#endif