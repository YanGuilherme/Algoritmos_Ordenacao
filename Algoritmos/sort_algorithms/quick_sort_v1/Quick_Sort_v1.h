#ifndef QUICK_SORT_V1
#define QUICK_SORT_V1

#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class QuickSortV1: public Algoritmo{
    public:
        QuickSortV1();
        ~QuickSortV1();
        void executar(DadosEntrada*);
    private:
        void quick_sort_v1(int*, int, int);

};



#endif