#ifndef QUICK_SORT_V3
#define QUICK_SORT_V3

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class QuickSortV3 : public Algoritmo{
    public:
        void ordenar(DadosEntrada*);
        QuickSortV3();
        ~QuickSortV3();
    private:
        void quick_sort_v3(int*,int,int);
        int calcularMediana(int,int,int); 


};

#endif