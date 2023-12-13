#ifndef HEAP_SORT_MIN_H
#define HEAP_SORT_MIN_H

#include "Heap_min.h"
#include "../Algoritmo.h"

class HeapMin;

class HeapSortMin:public Algoritmo{
    private:
        void heapsort(DadosEntrada*);
    public:
        HeapSortMin();
        ~HeapSortMin();
        void executar(DadosEntrada *);

        
};


#endif