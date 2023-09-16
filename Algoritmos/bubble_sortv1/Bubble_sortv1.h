#ifndef BUBBLE_SORTV1_H
#define BUBBLE_SORTV1_H

#include "../Algoritmo.h"
#include "../../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../../Arquivo.h"

class BubbleSortv1: public Algoritmo{
    public:
    BubbleSortv1();
    ~BubbleSortv1();
    void ordenar(DadosEntrada*);
};


#endif