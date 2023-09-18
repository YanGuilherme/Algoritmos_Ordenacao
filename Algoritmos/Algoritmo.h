#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <iostream>
#include <string>
#include "../DadosEntrada.h"
using namespace std;


class DadosEntrada;

class Algoritmo{
    public:
        Algoritmo(string);
        double duracao;
        virtual void ordenar(DadosEntrada *) = 0; // ;)
        ~Algoritmo(){}
        double getTempoAtual();
        void exibir_duracao(DadosEntrada);
        string getNome();
    private:
        string nome;

};

#endif