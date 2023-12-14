#ifndef QUICK_SORT_V2
#define QUICK_SORT_V2

#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class QuickSortV2: public Algoritmo{
    public:
        QuickSortV2();
        ~QuickSortV2();
        void executar(DadosEntrada*);
    private:
        void quick_sort_v2(int*, int, int);
};


#endif