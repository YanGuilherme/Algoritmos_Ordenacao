#ifndef HEAP_EXTRACT_MIN_H
#define HEAP_EXTRACT_MIN_H
#include "../Algoritmo.h"
#include "Heap_min.h"

class HeapMin;
class HeapExtractMin: public Algoritmo, public HeapMin{
    public:
        HeapExtractMin();
        ~HeapExtractMin();
        void build_min_heap(DadosEntrada*);
        void executar(DadosEntrada*);
    private:
        int extractMin(DadosEntrada*);

};


#endif