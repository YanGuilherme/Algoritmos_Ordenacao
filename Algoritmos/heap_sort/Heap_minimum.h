#ifndef HEAP_MINIMUM_H
#define HEAP_MINIMUM_H
#include "Heap_min.h"
#include "../../DadosEntrada.h"
#include "../Algoritmo.h"

class Heap_Minimum: public HeapMin, public Algoritmo{
    public:
        static void exibir_heap();
        static void exibir_min();
        void executar();
    private:

};





#endif