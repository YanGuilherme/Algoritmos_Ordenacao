#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class BubbleSort: public Algoritmo{
    public:
    BubbleSort();
    ~BubbleSort();
    void ordenar(DadosEntrada*);
};


#endif