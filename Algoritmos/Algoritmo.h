#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <string>
#include "../DadosEntrada.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


class DadosEntrada;

class Algoritmo{
    public:
        Algoritmo(string);
        double duracao;
        virtual void executar(DadosEntrada *) = 0; // ;)
        virtual ~Algoritmo() {}
        static double getTempoAtual();
        void exibir_duracao(DadosEntrada);
        string getNome();
    private:
        string nome;
        
};

#endif