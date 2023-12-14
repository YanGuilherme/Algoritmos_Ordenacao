#ifndef HEAP_INCREASE_KEY_H
#define HEAP_INCREASE_KEY_H
#include "Heap_min.h"
#include "../Algoritmo.h"

class HeapMin;

class MaxIncreaseKey:public Algoritmo, public HeapMin{
    public:
        void executar(DadosEntrada*);
        void build_min_heap(DadosEntrada*);
        MaxIncreaseKey();
        ~MaxIncreaseKey();
    private:
        void increase_key(DadosEntrada*);
};

#endif