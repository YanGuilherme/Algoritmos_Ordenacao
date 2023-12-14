#ifndef HEAP_SORT_MIN_H
#define HEAP_SORT_MIN_H

#include "Heap_min.h"
#include "../Algoritmo.h"

class HeapMin;

class HeapSortMin:public Algoritmo, public HeapMin{
    private:
        void heapsort(DadosEntrada*);
    public:
        void build_min_heap(DadosEntrada*);
        HeapSortMin();
        ~HeapSortMin();
        void executar(DadosEntrada *);

        
};


#endif