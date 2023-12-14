#ifndef QUICK_SORT_V3
#define QUICK_SORT_V3

#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class QuickSortV3 : public Algoritmo{
    public:
        void executar(DadosEntrada*);
        QuickSortV3();
        ~QuickSortV3();
    private:
        void quick_sort_v3(int*,int,int);
        void calcularMediana(int*,int*,int); 
        void insertion_sort(int*, int);


};

#endif