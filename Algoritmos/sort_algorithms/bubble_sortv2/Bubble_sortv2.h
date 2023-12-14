#ifndef BUBBLE_SORTV2_H
#define BUBBLE_SORTV2_H

#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class BubbleSortv2: public Algoritmo{
    public:
        BubbleSortv2();
        ~BubbleSortv2();
        void executar(DadosEntrada*);
};


#endif