#ifndef QUICK_SORT_V4
#define QUICK_SORT_V4

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class QuickSortV4: public Algoritmo{
    public:
        QuickSortV4();
        ~QuickSortV4();
        void ordenar(DadosEntrada*);
    private:
        int escolherPivoAleatorio(int,int);
        void quick_sort_v4(int*,int,int);
};


#endif