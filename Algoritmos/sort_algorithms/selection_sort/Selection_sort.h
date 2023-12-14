#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "../../Algoritmo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"

class SelectionSort: public Algoritmo{
    public:
        SelectionSort();
        ~SelectionSort();
        void executar(DadosEntrada*);
};

#endif