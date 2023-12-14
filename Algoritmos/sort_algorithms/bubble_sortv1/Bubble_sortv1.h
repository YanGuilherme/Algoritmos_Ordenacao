#ifndef BUBBLE_SORTV1_H
#define BUBBLE_SORTV1_H

#include "../../Algoritmo.h"
#include "../../../DadosEntrada.h"
#include "../../../Arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class BubbleSortv1: public Algoritmo{
    public:
        BubbleSortv1();
        ~BubbleSortv1();
        void executar(DadosEntrada*);
        
};


#endif