#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class InsertionSort: public Algoritmo{
    public:
        InsertionSort();
        ~InsertionSort();
        void executar(DadosEntrada*);
};

#endif