#ifndef QUICK_SORT_V1
#define QUICK_SORT_V1

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class QuickSortV1: public Algoritmo{
    private:
        void troca(int *,int ,int) ;
        int particao(int *, int, int);
        void quick_sortv1(int*, int, int);
    public:
        QuickSortV1();
        ~QuickSortV1();
        void ordenar(DadosEntrada *);
};



#endif