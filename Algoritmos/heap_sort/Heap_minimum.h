#ifndef HEAP_MINIMUM_H
#define HEAP_MINIMUM_H
#include "Heap_min.h"
#include "../../DadosEntrada.h"
#include "../Algoritmo.h"

class HeapMin;
class HeapMinimum: public Algoritmo, public HeapMin{
    public:
        HeapMinimum();
        ~HeapMinimum();
        void build_min_heap(DadosEntrada*);
        void executar(DadosEntrada*);
    private:

};





#endif