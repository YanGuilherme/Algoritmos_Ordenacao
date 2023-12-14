#ifndef HEAP_MIN_H
#define HEAP_MIN_H

#include "../Algoritmo.h"
class HeapMin{
    public:
        HeapMin();
        ~HeapMin();
        virtual void build_min_heap(DadosEntrada*) = 0;
        static void min_heapify(DadosEntrada*, int ,int);
        static void exibir_heap(DadosEntrada*);
        int menor;


};

#endif