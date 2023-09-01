#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


#include "Algoritmo.h"
#include "DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <math.h>
#include <iostream>



class InsertionSort: public Algoritmo{
    public:
        InsertionSort();
        ~InsertionSort();
        double duracao;
        void ordenar(DadosEntrada*);
        void salvar_entrada(DadosEntrada);
        void salvar_saida(DadosEntrada);
        void salvar_tempos(DadosEntrada);
        void exibir_duracao(DadosEntrada);
        virtual void processar(DadosEntrada*);


};

#endif