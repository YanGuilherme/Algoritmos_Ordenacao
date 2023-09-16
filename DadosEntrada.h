#ifndef DADOSENTRADA_H
#define DADOSENTRADA_H

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <random>
#include <math.h>
#include <iostream>
#include <map>

using namespace std;

enum TipoEntrada{
    CRESCENTE,
    DECRESCENTE,
    RANDOM
};


class DadosEntrada{
    private:
    public:
        int tamanho, *vector;
        TipoEntrada tipo_entrada;
        DadosEntrada();
        DadosEntrada(int, TipoEntrada);
        string tipo;
        void make_vector();
        void exibe_vector();
        void escolha_tipo_entrada(int);
        void escolha_tamanho(int);
        void destroy_vector();
        int get_tamanho();
};









#endif