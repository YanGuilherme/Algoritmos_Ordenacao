#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "../DadosEntrada.h"

class DadosEntrada;

class Algoritmo{
    public:
        double duracao;
        virtual void ordenar(DadosEntrada *) = 0;
        ~Algoritmo(){}

};

#endif