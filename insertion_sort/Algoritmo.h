#ifndef ALGORITMO_H
#define ALGORITMO_H
#include "DadosEntrada.h"

class DadosEntrada;

class Algoritmo{
    public:
        virtual void processar(DadosEntrada *) = 0;

};

#endif