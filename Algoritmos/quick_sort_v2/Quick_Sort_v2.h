#ifndef QUICK_SORT_V2
#define QUICK_SORT_V2

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class QuickSortV2: public Algoritmo{
    private:
        long calcularMedia(int*,int,int);
        void troca(int *,int ,int) ;
        int particao(int *, int, int);
        void quick_sortv2(int*, int, int);
    public:
        QuickSortV2();
        ~QuickSortV2();
        void ordenar(DadosEntrada *);
};


#endif