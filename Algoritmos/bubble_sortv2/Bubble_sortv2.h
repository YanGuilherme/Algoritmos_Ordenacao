#ifndef BUBBLE_SORTV2_H
#define BUBBLE_SORTV2_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class BubbleSortv2: public Algoritmo{
    public:
    BubbleSortv2();
    ~BubbleSortv2();
    void ordenar(DadosEntrada*);
};


#endif