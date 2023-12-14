#ifndef MAX_HEAP_INSERT_H
#define MAX_HEAP_INSERT_H
#include "Heap_min.h"
#include "../Algoritmo.h"

class HeapMin;

class MaxHeapInsert: public Algoritmo, public HeapMin{
    public:
        MaxHeapInsert();
        ~MaxHeapInsert();
        void executar(DadosEntrada*);
        void build_min_heap(DadosEntrada*);

};

#endif