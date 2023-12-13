#ifndef HEAP_MIN_H
#define HEAP_MIN_H

#include "../Algoritmo.h"

class HeapMin{
    public:
        HeapMin();
        ~HeapMin();
        static void build_min_heap(DadosEntrada*);
        static void min_heapify(DadosEntrada*, int ,int);
};

#endif