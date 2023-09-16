#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class SelectionSort: public Algoritmo{
    public:
        SelectionSort();
        ~SelectionSort();
        void ordenar(DadosEntrada*);
};

#endif