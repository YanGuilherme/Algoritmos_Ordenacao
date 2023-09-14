#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class InsertionSort: public Algoritmo{
    public:
        InsertionSort();
        ~InsertionSort();
        void ordenar(DadosEntrada*);
};

#endif